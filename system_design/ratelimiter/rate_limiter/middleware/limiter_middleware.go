package middleware

import (
	"net/http"
	"rate_limiter/limiter"
	"rate_limiter/metrics"

	"github.com/gin-gonic/gin"
)

func RateLimitMiddleware(lim *limiter.RedisLimiter) gin.HandlerFunc {
	return func(c *gin.Context) {
		ip := c.ClientIP()
		path := c.FullPath() // 支持动态路由，使用 FullPath 更稳定
		key := ip + ":" + path

		allowed, err := lim.Allow(key)
		if err != nil {
			c.AbortWithStatusJSON(http.StatusInternalServerError, gin.H{"error": "rate limiter error"})
			return
		}

		if !allowed {
			metrics.Denied.WithLabelValues(path).Inc()
			c.AbortWithStatusJSON(http.StatusTooManyRequests, gin.H{"error": "too many requests"})
			return
		}

		metrics.Allowed.WithLabelValues(path).Inc()
		c.Next()
	}
}
