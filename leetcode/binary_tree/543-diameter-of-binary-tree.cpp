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
    int max_len = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        max_len = 0;
        dfs(root);
        return max_len - 1;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        max_len = max(max_len, L + R + 1);
        return max(L, R) + 1;
    }
};

int main() {
    Solution so;

    return 0;
}