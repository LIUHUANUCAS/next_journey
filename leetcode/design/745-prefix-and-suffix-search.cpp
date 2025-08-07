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
class WordFilter {
    struct TreeNode {
        int word_index;
        TreeNode* next[27];
    };
    void add(TreeNode* root, string& s, int i, int word_index) {
        if (i >= s.size())
            return;
        int idx = s[i] - 'a';
        if (root->next[idx] == nullptr)
            root->next[idx] = new TreeNode();
        root->next[idx]->word_index = word_index;
        add(root->next[idx], s, i + 1, word_index);
    }
    TreeNode* search(string& s) {
        auto r = root;
        for (auto it = s.begin(); it != s.end(); ++it) {
            int idx = *it - 'a';
            r = r->next[idx];
            if (r == nullptr)
                return nullptr;
        }
        return r;
    }
    void dfs(TreeNode* r, int& idx) {
        if (r == nullptr)
            return;

        for (auto n : r->next) {
            if (n != nullptr)
                dfs(n, idx);
        }
    }
    TreeNode* root;

   public:
    WordFilter(vector<string>& words) {
        root = new TreeNode();
        int n = words.size();
        for (int idx = 0; idx < n; ++idx) {
            string str(words[idx] + "{" + words[idx]);
            for (int i = 0; i < words[idx].size(); ++i) {
                string s(str.substr(i));
                add(root, s, 0, idx);
            }
        }
    }

    int f(string pref, string suff) {
        string w(suff + "{" + pref);
        auto r = search(w);
        if (r == nullptr)
            return -1;
        return r->word_index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
int main() {
    return 0;
}