
一致性哈希
虚拟节点个数，在初始化的时候就确定了。
1. 添加节点： node_name + "##VN" + vitual_node_id 生成哈希值，然后赋值给当前这个节点
```
 // 添加真实节点
    void addNode(const std::string& node) {
        for (int i = 0; i < virtual_node_count; ++i) {
            std::string vnode = node + "##VN" + std::to_string(i);
            size_t hash = hashFunc(vnode);
            ring[hash] = node;
        }
    }
```

2. 删除节点： 与添加节点类似，需要从hashmap中remove节点的记录
```
// 删除真实节点
    void removeNode(const std::string& node) {
        for (int i = 0; i < virtual_node_count; ++i) {
            std::string vnode = node + "##VN" + std::to_string(i);
            size_t hash = hashFunc(vnode);
            ring.erase(hash);
        }
    }
```

3. 查询key所在node：找到第一个大于等于hash值的node节点，也就是lower_bound node
```
// 获取 key 对应的节点
    std::string getNode(const std::string& key) const {
        if (ring.empty())
            return "";

        size_t hash = hashFunc(key);
        auto it = ring.lower_bound(hash);
        if (it == ring.end()) {
            // 如果超过最大 hash，回到第一个
            return ring.begin()->second;
        }
        return it->second;
    }
```

总结：引入虚拟节点， 把虚拟节点对应的数据assign 给相应的node，使得节点分布较为均匀
实际应用： 参考redis的hash slot, 16384个slot，然后依据redis节点个数，来分片整个数据，每个节点负责一段连续的slot. 其原理是consistent hash