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
    string key, value;
    int time;
    Node(string k = "", string v = "", int t = 0) : key(k), value(v), time(t) {}
};

class SSTable {
    int max_size;
    int time;
    map<string, Node> index;

   public:
    SSTable(int init_size = 10, int time = 0)
        : max_size(init_size), time(time) {}
    string get_filename() { return "sstable_" + to_string(time) + ".sstable"; }
    bool insert(const string key, const string value) {
        Node new_node(key, value, ++time);
        index[key] = new_node;
        return true;
    }
    bool is_full() { return index.size() == max_size; }
    void store_to_file() {
        string filename = get_filename();
        // Store the SSTable to a file (not implemented)
        cout << "Storing SSTable to " << filename << endl;
        for (auto& p : index) {
            cout << "Key: " << p.second.key << ", Value: " << p.second.value
                 << ", Time: " << p.second.time << endl;
        }
        cout << "--------------------------" << endl;
    }
    Node search(const string& key) {
        if (index.find(key) != index.end()) {
            return index[key];
        }
        return Node();  // Return an empty Node if not found
    }
};

class Storage {
    vector<SSTable> sstables;
    int max_size;
    int time;

   public:
    Storage(int size = 10, int time = 1) : max_size(size), time(time) {
        sstables.push_back(SSTable(max_size, time));
    }

    void insert(const string key, string value) {
        if (sstables.back().is_full()) {
            if (sstables.size() >= max_size) {
                store_to_file();
                sstables.clear();
            }
            sstables.push_back(SSTable(max_size, time));
        }
        time++;
        sstables.back().insert(key, value);
    }
    void store_to_file() {
        while (!sstables.empty()) {
            sstables.back().store_to_file();
            sstables.pop_back();
        }
    }
    Node search(string key) {
        for (auto it = sstables.rbegin(); it != sstables.rend(); ++it) {
            Node result = it->search(key);
            if (!result.key.empty()) {
                return result;  // Return the first found Node
            }
        }
        return Node();  // Return an empty Node if not found
    }

    void store(string filename) {}
    void load(string filename) {
        // Load SSTable from file (not implemented)
    }
};

int main() {
    Storage storage(3, 0);
    int n = 100;
    for (int i = 0; i < n; ++i) {
        string key = "key" + to_string(i);
        string value = "value" + to_string(i);
        storage.insert(key, value);
    }
    return 0;
}