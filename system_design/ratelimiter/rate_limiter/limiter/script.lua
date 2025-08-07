-- script.lua
local key = KEYS[1]
local capacity = tonumber(ARGV[1])
local rate = tonumber(ARGV[2])
local now = tonumber(ARGV[3])
local requested = tonumber(ARGV[4])

local tokens = tonumber(redis.call("HGET", key, "tokens") or capacity)
local timestamp = tonumber(redis.call("HGET", key, "timestamp") or now)

local delta = math.max(0, now - timestamp)
local refill = delta * rate
tokens = math.min(capacity, tokens + refill)

local allowed = tokens >= requested
if allowed then
    tokens = tokens - requested
end

redis.call("HSET", key, "tokens", tokens)
redis.call("HSET", key, "timestamp", now)
return allowed and 1 or 0
