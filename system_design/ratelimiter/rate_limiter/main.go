package main

import (
	"net/http"
	"rate_limiter/limiter"
	"rate_limiter/metrics"
	"rate_limiter/middleware"

	"github.com/gin-gonic/gin"
	"github.com/prometheus/client_golang/prometheus/promhttp"
	"github.com/redis/go-redis/v9"
)

func main() {
	rdb := redis.NewClient(&redis.Options{
		Addr: "localhost:6379",
	})

	rl := limiter.NewRedisLimiter(rdb, "ratelimit", 50, 50)
	metrics.Init()

	r := gin.Default()
	r.Use(middleware.RateLimitMiddleware(rl))

	r.GET("/hello", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{"message": "hello world"})
	})

	r.GET("/metrics", gin.WrapH(promhttp.Handler()))
	r.Run(":8080")
}
