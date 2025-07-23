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
struct Iterator {
    stack<TreeNode*> st;
    Iterator(TreeNode* root) { push(root); }

    TreeNode* peek() {
        if (!st.empty())
            return st.top();
        return nullptr;
    }

    bool has_next() { return !st.empty(); }

    TreeNode* next() {
        auto x = st.top();
        st.pop();
        push(x->right);
        return x;
    }

    void push(TreeNode* r) {
        if (r == nullptr)
            return;
        while (r) {
            st.push(r);
            r = r->left;
        }
    }
};

class Solution {
   public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        Iterator it1(root1), it2(root2);
        vector<int> ret;
        while (it1.has_next() && it2.has_next()) {
            auto x = it1.peek(), y = it2.peek();
            if (x->val < y->val) {
                ret.push_back(x->val);
                it1.next();
            } else {
                ret.push_back(y->val);
                it2.next();
            }
        }
        while (it1.has_next()) {
            auto x = it1.peek();
            ret.push_back(x->val);
            it1.next();
        }
        while (it2.has_next()) {
            auto x = it2.peek();
            ret.push_back(x->val);
            it2.next();
        }
        return ret;
    }
};
int main() {
    Solution so;

    return 0;
}