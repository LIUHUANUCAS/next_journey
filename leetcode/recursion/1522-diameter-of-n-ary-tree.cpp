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
    int max_len;

   public:
    int diameter(Node* root) {
        max_len = 1;
        dfs(root);
        return max_len - 1;
    }
    int dfs(Node* root) {
        if (root == nullptr)
            return 0;
        int r = 0, max_child_len = 0;
        for (auto node : root->children) {
            r = dfs(node);
            max_len = max(max_len, r + max_child_len + 1);
            max_child_len = max(max_child_len, r);
        }
        return max_child_len + 1;
    }
};
int main() {
    Solution so;

    return 0;
}