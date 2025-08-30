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
struct NodeStatus {
    int include;  // include root
    int left;
    int right;
    int not_include;  // not include
    NodeStatus(int a, int b, int c, int d)
        : include(a), left(b), right(c), not_include(d) {}
    NodeStatus() {}
};

class Solution {
   public:
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr)
                return 0;
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            ret = max(ret, left + right + root->val);
            return max(max(left, right) + root->val, 0);
        };
        dfs(root);
        return ret;
    }
    int maxPathSum2(TreeNode* root) {
        auto r = dfs(root);
        return max(r.include, r.not_include);
    }
    NodeStatus dfs(TreeNode* root) {
        if (root == nullptr)
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int left = root->val + max(max(l.left, l.right), 0);
        int lmax = max(l.left, l.right);
        if (lmax > 0)
            left += lmax;
        int right = root->val;
        int rmax = max(r.left, r.right);
        if (rmax > 0)
            right += rmax;
        int include = root->val;
        if (lmax > 0)
            include += lmax;
        if (rmax > 0)
            include += rmax;

        int not_include =
            max(max(l.not_include, l.include), max(r.not_include, r.include));

        return {include, left, right, not_include};
    }
    /**
    10: {10,10,10,INT_MIN};
    1: {1,1,1,INT_MIN};
    29:{40,39,30,10};
    15r:{15,15,15,INT_MIN};
    7:{7,7,7,INT_MIN};
    -20:{2,-5,-13, 15}
    15root:{,15+39,15+(-5),}
    **/
};
int main() {
    Solution so;

    return 0;
}