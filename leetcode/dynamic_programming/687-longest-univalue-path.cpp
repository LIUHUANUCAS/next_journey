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
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr)
                return -1;
            int left = dfs(root->left) + 1;
            int right = dfs(root->right) + 1;
            if (root->left && root->left->val != root->val)
                left = 0;
            if (root->right && root->right->val != root->val)
                right = 0;
            ret = max(ret, left + right);
            return max(left, right);
        };
        dfs(root);
        return ret;
    }
    int longestUnivaluePath2(TreeNode* root) {
        int ret = 0;

        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr)
                return pair<int, int>{0, INT_MAX};  // {length,NodeValue};
            auto L = dfs(root->left);
            auto R = dfs(root->right);
            int left = 0, right = 0;
            if (L.second == root->val) {
                left = 1 + L.first;
            }
            if (R.second == root->val) {
                right += 1 + R.first;
            }
            ret = max(ret, left + right);
            return pair<int, int>{max(left, right), root->val};
        };
        dfs(root);
        return ret;
    }
};
int main() {
    Solution so;

    return 0;
}