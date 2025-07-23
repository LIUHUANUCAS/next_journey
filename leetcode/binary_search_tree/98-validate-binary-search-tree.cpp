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
    bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr)
            return true;
        if (root->val <= lower || root->val >= upper)
            return false;
        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }
    bool dfs(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        auto min_right_value = min(root->right);
        auto max_left_value = max(root->left);
        bool balanced = true;
        if (min_right_value != nullptr)
            balanced = balanced && min_right_value->val > root->val;
        if (max_left_value != nullptr)
            balanced = balanced && max_left_value->val < root->val;
        return balanced && dfs(root->left) && dfs(root->right);
    }

    TreeNode* min(TreeNode* root) {
        if (root == nullptr || root->left == nullptr)
            return root;
        return min(root->left);
    }

    TreeNode* max(TreeNode* root) {
        if (root == nullptr || root->right == nullptr)
            return root;
        return max(root->right);
    }
};
int main() {
    Solution so;

    return 0;
}