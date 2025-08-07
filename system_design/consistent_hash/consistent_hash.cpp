#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class ConsistentHash {
   public:
    ConsistentHash(int virtual_nodes = 100)
        : virtual_node_count(virtual_nodes) {}

    // 添加真实节点
    void addNode(const std::string& node) {
        for (int i = 0; i < virtual_node_count; ++i) {
            std::string vnode = node + "##VN" + std::to_string(i);
            size_t hash = hashFunc(vnode);
            ring[hash] = node;
        }
    }

    // 删除真实节点
    void removeNode(const std::string& node) {
        for (int i = 0; i < virtual_node_count; ++i) {
            std::string vnode = node + "##VN" + std::to_string(i);
            size_t hash = hashFunc(vnode);
            ring.erase(hash);
        }
    }

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

    // 打印哈希环（调试用）
    void printRing() const {
        for (const auto& [h, node] : ring) {
            std::cout << h << " -> " << node << std::endl;
        }
    }

   private:
    std::map<size_t, std::string> ring;  // hash ring
    int virtual_node_count;

    size_t hashFunc(const std::string& key) const {
        return std::hash<std::string>{}(key);
    }
};

int main() {
    ConsistentHash ch(10);  // 每个节点10个虚拟节点

    ch.addNode("NodeA");
    ch.addNode("NodeB");
    ch.addNode("NodeC");

    std::vector<std::string> keys = {"user1", "user2", "video42", "session88",
                                     "cart55"};

    for (const auto& key : keys) {
        std::cout << key << " is mapped to " << ch.getNode(key) << "\n";
    }

    std::cout << "\n--- Remove NodeB ---\n";
    ch.removeNode("NodeB");

    for (const auto& key : keys) {
        std::cout << key << " is mapped to " << ch.getNode(key) << "\n";
    }

    return 0;
}
