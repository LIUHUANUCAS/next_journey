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
    vector<int> ret;

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ret.clear();
        int m = matrix.size(), n = matrix[0].size();
        dfs(matrix, 0, 0, m - 1, n - 1);
        return ret;
    }
    void dfs(vector<vector<int>>& m, int i, int j, int l, int r) {
        if (i > l || j > r)
            return;
        if (i == l) {
            for (int col = j; col <= r; ++col) {
                ret.push_back(m[i][col]);
            }
            return;
        }
        if (j == r) {
            for (int row = i; row <= l; ++row)
                ret.push_back(m[row][j]);
            return;
        }
        for (int col = j; col < r; ++col) {
            ret.push_back(m[i][col]);
        }
        for (int row = i; row < l; row++) {
            ret.push_back(m[row][r]);
        }
        for (int col = r; col > j; --col) {
            ret.push_back(m[l][col]);
        }

        for (int row = l; row > i; --row) {
            ret.push_back(m[row][j]);
        }
        dfs(m, i + 1, j + 1, l - 1, r - 1);
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        auto ret = so.spiralOrder(A);
        printvector(ret);  // [1,2,3,6,9,8,7,4,5]
    }
    {
        A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        auto ret = so.spiralOrder(A);
        printvector(ret);  // [1,2,3,4,8,12,11,10,9,5,6,7]
    }
    {
        A = {{1}};
        auto ret = so.spiralOrder(A);
        printvector(ret);  // [1]
    }
    {
        A = {};
        auto ret = so.spiralOrder(A);
        printvector(ret);  // []
    }
    return 0;
}