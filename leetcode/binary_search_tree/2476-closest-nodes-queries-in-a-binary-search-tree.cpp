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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> array;
        dfs(root, array);
        vector<vector<int>> ret;
        for (auto q : queries) {
            int a = -1, b = -1;
            auto lower = lower_bound(array.begin(), array.end(), q);
            auto upper = upper_bound(array.begin(), array.end(), q);
            if (upper != array.end() && *upper >= q) {
                b = *upper;
            }
            if (lower != array.end()) {
                if (*lower == q) {
                    a = *lower;
                    b = a;
                } else if (*lower > q && lower != array.begin()) {
                    a = *(lower - 1);
                }
            } else {
                a = *(lower - 1);
            }
            ret.push_back({a, b});
        }
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