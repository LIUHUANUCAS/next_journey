#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../header/data_type.h"

using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : isEnd(false), children(26, nullptr) {}
};
class Trie {
    TrieNode* children;

   public:
    Trie() { children = new TrieNode(); }
    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children->children[i]) {
                delete children->children[i];
            }
        }
        delete children;
    }

    void insert(string word) {
        TrieNode* node = this->children;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = this->children;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = this->children;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    // Solution so;
    Trie* obj = new Trie();
    {
        string word = "apple", prefix("app");
        obj->insert(word);
        bool param_2 = obj->search(word);
        bool param_3 = obj->startsWith(prefix);
        cout << "str:" << word << " search:" << param_2
             << " startsWith:" << param_3 << endl;  // true true
    }
    return 0;
}