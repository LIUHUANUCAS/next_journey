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
    int val;

   public:
    int kthSmallest(TreeNode* root, int k) {
        val = -1;
        inOrder(root, k);
        return val;
    }
    void inOrder(TreeNode* root, int& k) {
        if (root == nullptr)
            return;
        inOrder(root->left, k);
        if (--k == 0) {
            val = root->val;
        }
        inOrder(root->right, k);
    }
};
int main() {
    Solution so;

    return 0;
}