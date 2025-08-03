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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorder_map.clear();
        int n = inorder.size();
        reverse(postorder.begin(), postorder.end());
        for (int i = 0; i < n; ++i) {
            inorder_map[inorder[i]] = i;
        }
        return build(postorder, 0, n - 1, inorder, 0, n - 1);
    }
    TreeNode* build(vector<int>& preorder,
                    int i,
                    int j,
                    vector<int>& inorder,
                    int l,
                    int r) {
        if (i > j || i < 0 || l > r || l < 0)
            return nullptr;
        if (i == j)
            return new TreeNode(preorder[i]);
        int value = preorder[i];
        auto node = new TreeNode(value);
        int idx = inorder_map[value];
        int len = r - idx;
        node->right = build(preorder, i + 1, i + len, inorder, idx + 1, r);
        node->left = build(preorder, i + len + 1, j, inorder, l, idx - 1);
        return node;
    }
};
int main() {
    Solution so;

    return 0;
}