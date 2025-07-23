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
struct TrieNode {
    bool is_end;
    TrieNode* next[26];
    TrieNode() : is_end(false) { memset(next, 0x00, sizeof(TrieNode*) * 26); }
};
class WordDictionary {
    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        auto n = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (n->next[idx] == nullptr) {
                n->next[idx] = new TrieNode();
            }
            n = n->next[idx];
        }
        n->is_end = true;
    }

    bool search(string word) { return dfs(root, word, 0); }
    bool dfs(TrieNode* start, string& word, int index) {
        if (start == nullptr)
            return false;
        int size = word.size();
        if (index == size)
            return start->is_end;
        auto n = start;
        for (int i = index; i < size; ++i) {
            char c = word[i];
            if (c == '.') {
                for (auto next : n->next) {
                    if (dfs(next, word, i + 1))
                        return true;
                }
                return false;
            } else {
                int idx = c - 'a';
                if (n->next[idx] == nullptr)
                    return false;
                n = n->next[idx];
            }
        }
        return n->is_end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << wd.search("pad") << endl;    // return False
    cout << wd.search("bad") << endl;    // return True
    cout << wd.search(".ad") << endl;    // return True
    cout << wd.search("b..") << endl;    // return True
    cout << wd.search("b..d") << endl;   // return False
    cout << wd.search("b..d.") << endl;  // return False

    return 0;
}