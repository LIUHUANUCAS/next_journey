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
    int ret;
    double delta;

   public:
    int closestValue(TreeNode* root, double target) {
        delta = INT_MAX;
        dfs(root, target);
        return ret;
    }
    void dfs(TreeNode* root, double target) {
        if (root == nullptr)
            return;
        double x = abs(target - root->val);
        if (x < delta) {
            delta = x;
            ret = root->val;
        } else if (x == delta) {
            if (root->val < ret) {
                ret = root->val;
            }
        }
        if (root->val < target) {
            dfs(root->right, target);
        } else if (root->val > target) {
            dfs(root->left, target);
        }
    }
};
int main() {
    Solution so;

    return 0;
}