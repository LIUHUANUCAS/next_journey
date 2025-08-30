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
class Solution {
   public:
    bool validateBinaryTreeNodes(int n,
                                 vector<int>& leftChild,
                                 vector<int>& rightChild) {
        vector<int> indgree(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1 && ++indgree[leftChild[i]] > 1)
                return false;
            if (rightChild[i] != -1 && ++indgree[rightChild[i]] > 1)
                return false;
        }
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indgree[i] == 0) {
                if (root != -1)
                    return false;
                root = i;
            }
        }
        vector<int> visited(n, 0);
        function<void(int)> dfs = [&](int v) {
            if (v == -1)
                return;
            visited[v] = 1;
            dfs(leftChild[v]);
            dfs(rightChild[v]);
        };
        dfs(root);
        for (auto it = visited.begin(); it != visited.end(); ++it) {
            if (!*it)
                return false;  // all node visted from root;
        }
        return true;
    }
};
int main() {
    Solution so;
    int n;
    vector<int> leftChild, rightChild;
    {
        n = 4;
        leftChild = {1, -1, 3, -1};
        rightChild = {2, -1, -1, -1};
        auto r = so.validateBinaryTreeNodes(n, leftChild, rightChild);
        cout << "r:" << r << endl;
    }
    {
        n = 2;
        leftChild = {-1, -1};
        rightChild = {-1, -1};
        auto r = so.validateBinaryTreeNodes(n, leftChild, rightChild);
        cout << "r:" << r << endl;
    }
    {
        n = 5;
        leftChild = {1, 2, -1, 4, -1};
        rightChild = {3, -1, -1, -1, -1};
        auto r = so.validateBinaryTreeNodes(n, leftChild, rightChild);
        cout << "r:" << r << endl;
    }
    return 0;
}