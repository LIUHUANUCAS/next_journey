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

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    Node* cloneTree(Node* root) { return dfs(root); }
    Node* dfs(Node* root) {
        if (root == nullptr)
            return root;
        if (root->children.empty()) {
            return new Node(root->val, {});
        }
        auto new_root = new Node(root->val, root->children);
        int n = root->children.size();
        for (int i = 0; i < n; ++i) {
            new_root->children[i] = dfs(root->children[i]);
        }
        return new_root;
    }
};
int main() {
    Solution so;

    return 0;
}