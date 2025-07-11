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
        queue<Node*> que;
        if (root == nullptr)
            return root;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto x = que.front();
                que.pop();
                if (i < size - 1) {
                    x->next = que.front();
                } else {
                    x->next = nullptr
                }
                if (x->left)
                    que.push(x->left);
                if (x->right)
                    que.push(x->right);
            }
        }
        return root;
    }
};
int main() {
    Solution so;

    return 0;
}