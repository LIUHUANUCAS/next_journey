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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
    bool dfs(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        int t = targetSum - root->val;
        if (t == 0 && root->left == nullptr && root->right == nullptr)
            return true;
        return dfs(root->left, t) || dfs(root->right, t);
    }
};

int main() {
    Solution so;

    return 0;
}