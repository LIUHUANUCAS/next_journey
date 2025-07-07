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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        int level = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            res.push_back(vector<int>(size, 0));
            for (int i = 0; i < size; ++i) {
                auto r = que.front();
                que.pop();
                res.back()[i] = r->val;
                if (r->left)
                    que.push(r->left);
                if (r->right)
                    que.push(r->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution so;

    return 0;
}