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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> A;
        dfs(root, p, A);
        if (A.size() < 2)
            return nullptr;
        return A.back();
    }
    void dfs(TreeNode* root, TreeNode* p, vector<TreeNode*>& res) {
        if (root == nullptr)
            return;
        dfs(root->left, p, res);
        int size = res.size();
        if (root->val == p->val) {
            res.push_back(p);
        }
        if (size == 1) {
            res.push_back(root);
        }
        dfs(root->right, p, res);
    }
};
int main() {
    Solution so;

    return 0;
}