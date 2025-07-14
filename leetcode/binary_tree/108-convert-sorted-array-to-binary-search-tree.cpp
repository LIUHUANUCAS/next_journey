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
   public:
    TreeNode* sortedArrayToBST(vector<int>& A) {
        int n = A.size();
        return dfs(A, 0, n - 1);
    }
    TreeNode* dfs(vector<int>& A, int i, int j) {
        int size = A.size();
        if (i > j || i < 0 || j >= size) return nullptr;
        if (i == j) return new TreeNode(A[i]);
        int mid = i + (j - i) / 2;
        return new TreeNode(A[mid], dfs(A, i, mid - 1), dfs(A, mid + 1, j));
    }
};
int main() {
    Solution so;

    return 0;
}