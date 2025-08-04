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
    vector<vector<int>> ret;
    int k;

   public:
    vector<vector<int>> generateMatrix(int n) {
        ret.clear();
        ret.resize(n, vector<int>(n, 0));
        k = 1;
        dfs(ret, 0, 0, n - 1, n - 1);
        return ret;
    }
    void dfs(vector<vector<int>>& ret, int i, int j, int l, int r) {
        if (i > l || j > r)
            return;
        if (i == l) {
            for (int col = j; col <= r; ++col) {
                ret[i][col] = k++;
            }
            return;
        }
        if (j == r) {
            for (int row = i; row <= l; ++row)
                ret[row][j] = k++;
            return;
        }
        for (int col = j; col < r; ++col) {
            ret[i][col] = k++;
        }
        for (int row = i; row < l; row++) {
            ret[row][r] = k++;
        }
        for (int col = r; col > j; --col) {
            ret[l][col] = k++;
        }

        for (int row = l; row > i; --row) {
            ret[row][j] = k++;
        }
        dfs(ret, i + 1, j + 1, l - 1, r - 1);
    }
};
int main() {
    Solution so;
    int n;
    {
        n = 3;
        auto ret = so.generateMatrix(n);
        printvector(ret);  // [[1,2,3],[8,9,4],[7,6,5]]
    }
    {
        n = 1;
        auto ret = so.generateMatrix(n);
        printvector(ret);  // [[1]]
    }
    {
        n = 4;
        auto ret = so.generateMatrix(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }
        printvector(ret);  // [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
    }
    return 0;
}