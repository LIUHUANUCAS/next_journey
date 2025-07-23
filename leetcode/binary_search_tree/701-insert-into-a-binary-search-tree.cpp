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
    TreeNode* insertIntoBST(TreeNode* root, int val) { return dfs(root, val); }
    TreeNode* dfs(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        if (root->val < val) {
            root->right = dfs(root->right, val);
            return root;
        } else if (root->val > val) {
            root->left = dfs(root->left, val);
            return root;
        }
        return root;
    }
};
int main() {
    Solution so;

    return 0;
}