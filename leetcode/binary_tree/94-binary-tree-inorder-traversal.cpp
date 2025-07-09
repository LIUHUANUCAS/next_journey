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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
    void dfs(TreeNode* root, vector<int>& ret) {
        if (root == nullptr)
            return;
        dfs(root->left, ret);
        ret.push_back(root->val);
        dfs(root->right, ret);
    }
};
int main() {
    Solution so;

    return 0;
}