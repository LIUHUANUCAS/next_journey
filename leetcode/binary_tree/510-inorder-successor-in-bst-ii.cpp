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
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
   public:
    Node* inorderSuccessor(Node* node) {
        if (node == nullptr)
            return node;

        if (node->right) {
            auto next = node->right;
            while (next->left)
                next = next->left;
            return next;
        }

        auto parent = node->parent, cur = node;

        while (parent && parent->right == cur) {
            cur = parent;
            parent = parent->parent;
        }
        return parent;
    }
};
int main() {
    Solution so;

    return 0;
}