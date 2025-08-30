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
/*
// Definition for a Node.
*/
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        vector<Node*> pre;

        function<void(Node*, int)> dfs = [&](Node* node, int depth) {
            if (node == nullptr)
                return;
            if (depth == pre.size()) {
                pre.push_back(node);
            } else {
                pre[depth]->next = node;
                pre[depth] =
                    node;  // replace as the left most node without next
            }
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        };
        dfs(root, 0);
        return root;
    }
};
int main() {
    Solution so;

    return 0;
}