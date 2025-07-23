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
    TreeNode* deleteNode(TreeNode* root, int key) { return dfs(root, key); }
    TreeNode* dfs(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (key < root->val) {
            root->left = dfs(root->left, key);
            return root;
        } else if (key > root->val) {
            root->right = dfs(root->right, key);
            return root;
        } else {  // delete current root node, 1.find the right_min,2. delete
                  // right_min 3. update the right_min->left,right_min->left  as
                  // the root->left and the deleted min node in root->right
                  // value
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            auto right_min = min(root->right);
            // right_min->right = delete_min(root->right);
            right_min->right = dfs(root->right, right_min->val);
            right_min->left = root->left;
            return right_min;
        }
    }

    TreeNode* delete_min(TreeNode* root) {
        if (root->left == nullptr)
            return root->right;
        root->left = delete_min(root->left);
        return root;
    }

    TreeNode* min(TreeNode* root) {
        if (root == nullptr)
            return root;
        if (root->left == nullptr)
            return root;
        return min(root->left);
    }
};
int main() {
    Solution so;

    return 0;
}