#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../header/data_type.h"

using namespace std;
class Trie {
    struct TrieNode {
        int count;
        int end;
        string word;
        TrieNode* next[26];
    };
    void add(TrieNode* root, string& w) {
        for (auto c : w) {
            int idx = c - 'a';
            if (root->next[idx] == nullptr)
                root->next[idx] = new TrieNode();
            root->next[idx]->count++;
            root = root->next[idx];
        }
        root->end++;
        root->word = w;
    }
    TrieNode* search(TrieNode* root, string& word) {
        for (auto c : word) {
            int idx = c - 'a';
            if (root->next[idx] == nullptr)
                return nullptr;
            if (root->next[idx]->count == 0)
                return nullptr;
            root = root->next[idx];
        }
        return root;
    }

    int _delete(TrieNode* root, string& word) {
        for (auto c : word) {
            int idx = c - 'a';
            if (root->next[idx] == nullptr)
                return 0;
            if (root->next[idx]->count == 0)
                return 0;
            root->next[idx]->count--;
            root = root->next[idx];
        }
        return root->end--;
    }
    TrieNode* root;

   public:
    Trie() { root = new TrieNode(); }

    void insert(string word) { add(root, word); }

    int countWordsEqualTo(string word) {
        auto r = search(root, word);
        if (r == nullptr)
            return 0;

        return r->end;
    }

    int countWordsStartingWith(string prefix) {
        auto r = search(root, prefix);
        if (r == nullptr)
            return 0;
        return r->count;
    }

    void erase(string word) {
        auto r = search(root, word);
        if (r == nullptr)
            return;
        _delete(root, word);
    }
};

int main() {
    Trie trie;
    {
        trie.insert("apple");
        cout << trie.countWordsEqualTo("apple") << endl;     // 1
        cout << trie.countWordsStartingWith("app") << endl;  // 1
        trie.erase("apple");
        cout << trie.countWordsEqualTo("apple") << endl;  // 0
    }

    {
        trie.insert("app");
        cout << trie.countWordsEqualTo("app") << endl;      // 1
        cout << trie.countWordsStartingWith("ap") << endl;  // 1
        trie.erase("app");
        cout << trie.countWordsEqualTo("app") << endl;  // 0
    }

    return 0;
}