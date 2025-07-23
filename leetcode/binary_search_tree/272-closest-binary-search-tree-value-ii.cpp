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
    priority_queue<pair<double, int>> pq;

   public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ret;
        pq = priority_queue<pair<double, int>>();
        inorder(root, target, k);
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ret.push_back(x.second);
        }
        return ret;
    }
    void inorder(TreeNode* root, double target, int k) {
        if (root == nullptr)
            return;
        inorder(root->left, target, k);
        pq.push({abs(target - root->val), root->val});
        if (pq.size() > k) {
            pq.pop();
        }
        inorder(root->right, target, k);
    }
};
int main() {
    Solution so;

    return 0;
}