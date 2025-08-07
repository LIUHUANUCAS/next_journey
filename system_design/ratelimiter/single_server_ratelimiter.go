package main

import (
	"fmt"
	"sync"
	"time"
)

// TokenBucket 限流器
type TokenBucket struct {
	capacity     int           // 桶容量
	tokens       int           // 当前令牌数
	refillRate   int           // 每次添加多少令牌
	refillPeriod time.Duration // 添加令牌的时间间隔
	mutex        sync.Mutex
}

// NewTokenBucket 创建一个新的令牌桶
func NewTokenBucket(capacity int, refillRate int, refillPeriod time.Duration) *TokenBucket {
	tb := &TokenBucket{
		capacity:     capacity,
		tokens:       capacity,
		refillRate:   refillRate,
		refillPeriod: refillPeriod,
	}
	go tb.refillTokens()
	return tb
}

// refillTokens 定时补充令牌
func (tb *TokenBucket) refillTokens() {
	ticker := time.NewTicker(tb.refillPeriod)
	defer ticker.Stop()
	for range ticker.C {
		tb.mutex.Lock()
		tb.tokens += tb.refillRate
		if tb.tokens > tb.capacity {
			tb.tokens = tb.capacity
		}
		tb.mutex.Unlock()
	}
}

// Allow 判断是否允许通过（消耗一个令牌）
func (tb *TokenBucket) Allow() bool {
	tb.mutex.Lock()
	defer tb.mutex.Unlock()
	if tb.tokens > 0 {
		tb.tokens--
		return true
	}
	return false
}

func main() {
	bucket := NewTokenBucket(5, 2, time.Second) // 初始容量 5，每秒补充 1 个

	for i := 0; i < 10; i++ {
		if bucket.Allow() {
			fmt.Printf("Request %d allowed at %v\n", i, time.Now())
		} else {
			fmt.Printf("Request %d denied at %v\n", i, time.Now())
		}
		time.Sleep(300 * time.Millisecond)
	}
}
