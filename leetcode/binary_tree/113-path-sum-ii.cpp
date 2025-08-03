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
    vector<vector<int>> ret;

   public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        ret.clear();
        dfs(root, targetSum, path);
        return ret;
    }
    bool dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr)
            return false;
        int t = targetSum - root->val;
        path.push_back(root->val);
        if (t == 0 && root->left == nullptr && root->right == nullptr) {
            ret.push_back(path);
            path.pop_back();
            return true;
        }
        int r = dfs(root->left, t, path);
        r += dfs(root->right, t, path);
        path.pop_back();
        return r;
    }
};
int main() {
    Solution so;

    return 0;
}