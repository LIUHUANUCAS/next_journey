#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../header/data_type.h"

using namespace std;

class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> umap;
    list<pair<int, int>> l;  // [k,v]
    int size;

   public:
    LRUCache(int capacity) { size = capacity; }

    int get(int key) {
        auto it = umap.find(key);
        if (it == umap.end())
            return -1;
        int value = it->second->second;
        l.splice(l.begin(), l, it->second);
        umap[key] = l.begin();
        return value;
    }

    void put(int key, int value) {
        auto it = umap.find(key);
        if (it != umap.end()) {  // found!
            // move to begin, update key in map
            it->second->second = value;
            l.splice(l.begin(), l, it->second);
            umap[key] = l.begin();
            return;
        }
        // not found
        l.push_front({key, value});
        umap[key] = l.begin();
        if (umap.size() > size) {
            umap.erase(l.back().first);
            l.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache so(100);

    return 0;
}