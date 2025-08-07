package limiter

import (
	"context"
	"embed"
	"fmt"
	"time"

	"github.com/redis/go-redis/v9"
)

//go:embed script.lua
var scriptFS embed.FS

type RedisLimiter struct {
	client    *redis.Client
	script    *redis.Script
	keyPrefix string
	capacity  int
	rate      int // per second
}

func NewRedisLimiter(client *redis.Client, keyPrefix string, capacity, rate int) *RedisLimiter {
	scriptContent, _ := scriptFS.ReadFile("script.lua")
	return &RedisLimiter{
		client:    client,
		script:    redis.NewScript(string(scriptContent)),
		keyPrefix: keyPrefix,
		capacity:  capacity,
		rate:      rate,
	}
}

func (r *RedisLimiter) Allow(key string) (bool, error) {
	now := time.Now().Unix()
	redisKey := fmt.Sprintf("%s:%s", r.keyPrefix, key)
	result, err := r.script.Run(context.Background(), r.client, []string{redisKey},
		r.capacity, r.rate, now, 1).Result()
	if err != nil {
		return false, err
	}
	return result.(int64) == 1, nil
}
