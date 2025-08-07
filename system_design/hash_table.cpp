#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct Node {
    string key;
    string value;
    int time;
    int offset;
    Node(string k = "", string val = "", int t = 0, int o = 0)
        : key(k), value(val), time(t), offset(o) {}
};
vector<Node> merge(vector<Node>& a, vector<Node>& b) {
    vector<Node> merged;
    map<string, Node> index;

    for (const auto& node : a) {
        index[node.key] = node;
    }
    for (const auto& node : b) {
        if (index.find(node.key) == index.end()) {
            index[node.key] = node;
        } else if (index[node.key].time < node.time) {
            index[node.key] = node;
        }
    }

    for (const auto& pair : index) {
        merged.push_back(pair.second);
    }
    sort(merged.begin(), merged.end(),
         [](const Node& a, const Node& b) { return a.time < b.time; });
    return merged;
}
vector<Node> compress(const vector<Node>& table) {
    map<string, Node> index;
    for (auto it = table.rbegin(); it != table.rend(); ++it) {
        if (index.find(it->key) == index.end()) {
            index[it->key] = *it;
        }
    }
    vector<Node> compressed;
    for (const auto& pair : index) {
        compressed.push_back(pair.second);
    }
    sort(compressed.begin(), compressed.end(),
         [](const Node& a, const Node& b) { return a.time < b.time; });
    return compressed;
}
class Storage {
    vector<Node> table;
    int time;

   public:
    Storage() : time(0) {}
    void compress() {}
    void insert(const string& key, string value) {
        ++time;
        table.push_back(Node(key, value, time, table.size()));
    }

    Node search(string key) { return Node(); }

    void store(string filename) {
        map<string, Node> index;
        for (auto it = table.rbegin(); it != table.rend(); ++it) {
            if (index.find(it->key) == index.end()) {
                index[it->key] = *it;
            }
        }
        vector<Node> compressed;
        for (const auto& pair : index) {
            compressed.push_back(pair.second);
        }
        sort(compressed.begin(), compressed.end(),
             [](const Node& a, const Node& b) { return a.time < b.time; });
        table = compressed;
        for (auto& t : table) {
            cout << "{[" << t.key << "," << t.value << "]->[time:" << t.time
                 << ",offset:" << t.offset << "]}" << endl;
        }
    }
    void load(string filename) {}
};

int main() {
    Storage storage;
    storage.insert("key1", "value1");
    storage.insert("key2", "value2");
    storage.insert("key1", "value3");  // Update key1
    storage.store("");
    return 0;
}