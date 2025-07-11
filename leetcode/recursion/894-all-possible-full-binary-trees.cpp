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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n & 1 == 0)
            return {};
        return dfs(n);
    }
    vector<TreeNode*> dfs(int n) {
        if (n == 1)
            return {new TreeNode(0)};
        vector<TreeNode*> res;

        for (int i = 1; i < n; i += 2) {
            auto left = dfs(i);
            auto right = dfs(n - i - 1);
            for (auto& x : left) {
                for (auto& y : right) {
                    auto root = new TreeNode(0);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution so;

    return 0;
}