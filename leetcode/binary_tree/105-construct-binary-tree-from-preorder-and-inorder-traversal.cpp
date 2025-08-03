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
    unordered_map<int, int> inorder_map;

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            inorder_map[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
    TreeNode* build(vector<int>& preorder,
                    int i,
                    int j,
                    vector<int>& inorder,
                    int l,
                    int r) {
        if (i > j || l > r || i < 0 || l < 0)
            return nullptr;
        if (i == j)
            return new TreeNode(preorder[i]);
        int value = preorder[i];
        auto node = new TreeNode(value);
        int idx = inorder_map[value];
        node->left = build(preorder, i + 1, i + idx - l, inorder, l, idx - 1);
        node->right = build(preorder, i + idx - l + 1, j, inorder, idx + 1, r);
        return node;
    }
};
int main() {
    Solution so;
    vector<int> preorder, inorder;
    {
        preorder = {3, 9, 20, 15, 7};
        inorder = {9, 3, 15, 20, 7};
        auto r = so.buildTree(preorder, inorder);
        print_tree(r);
    }
    {
        preorder = {1, 2};
        inorder = {2, 1};
        auto r = so.buildTree(preorder, inorder);
        print_tree(r);
    }
    {
        preorder = {1};
        inorder = {1};
        auto r = so.buildTree(preorder, inorder);
        print_tree(r);
    }
    return 0;
}