设计限流器
1. 限流器存在的位置
2. 限流算法
   1. 令牌桶: 以恒定速率放置token，一旦满了，就会drop，每个请求消耗一个token
   2. 漏桶算法：
      1. 队列大小，一旦队列满，请求request会被drop



改进设计：
1. 使用条件信号量，让请求阻塞在获取变量上，记得唤醒gorouting
2. redis lua 脚本 作为分布式限流
   1. hash_set key token [number], hash_set key last_freshed_time  [timestamp]
   2. refill the bucket and calculate the number token needed in request.
   3. update the [token,last_freshed_time]
3. 按照ip, API或者user来进行分组限流