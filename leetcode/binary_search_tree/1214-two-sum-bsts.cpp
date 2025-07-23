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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return inorder(root1, root2, target);
    }

    bool inorder(TreeNode* root1, TreeNode* root2, int target) {
        if (root1 == nullptr)
            return false;
        if (search_bst(root2, target - root1->val))
            return true;
        return inorder(root1->left, root2, target) ||
               inorder(root1->right, root2, target);
    }

    bool search_bst(TreeNode* root, int target) {
        if (root == nullptr)
            return false;
        if (root->val < target)
            return search_bst(root->right, target);
        else if (root->val > target)
            return search_bst(root->left, target);
        return root->val == target;
    }
};
int main() {
    Solution so;

    return 0;
}