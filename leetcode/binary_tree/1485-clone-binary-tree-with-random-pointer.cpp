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

//  * Definition for a Node.
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node* left, Node* right, Node* random)
        : val(x), left(left), right(right), random(random) {}
};

typedef Node NodeCopy;

class Solution {
    unordered_map<Node*, NodeCopy*> memo;

   public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        memo.clear();
        return dfs(root);
    }
    void copyNode(Node* root) {
        if (root == nullptr)
            return;

        if (root->random != nullptr) {
            auto new_root = memo[root];
            new_root->random = memo[root->random];
        }
        copyNode(root->left);
        copyNode(root->right);
    }
    NodeCopy* dfs(Node* root) {
        if (root == nullptr)
            return nullptr;
        if (memo.count(root)) {
            return memo[root];
        }
        auto new_root = new NodeCopy(root->val);
        memo[root] = new_root;
        new_root->left = dfs(root->left);
        new_root->right = dfs(root->right);
        new_root->random = dfs(root->random);
        return new_root;
    }
};

int main() {
    Solution so;

    return 0;
}