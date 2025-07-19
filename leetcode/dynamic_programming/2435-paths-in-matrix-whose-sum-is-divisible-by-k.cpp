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
    int numberOfPaths(vector<vector<int>>& A, int k) {
        int m = A.size(), n = A[0].size();
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0)));
        int v = A[0][0] % k;
        dp[0][0][v] = 1;
        for (int i = 1; i < m; ++i) {
            v += A[i][0] % k;
            dp[i][0][v % k] = 1;
        }
        v = A[0][0] % k;
        for (int j = 1; j < n; ++j) {
            v += A[0][j] % k;
            dp[0][j][v % k] = 1;
        }
        // printf("test\n");
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int l = 0; l < k; ++l) {
                    v = (l + A[i][j] % k) % k;
                    dp[i][j][v] +=
                        dp[i - 1][j][l] % mod + dp[i][j - 1][l] % mod;
                }
            }
        }
        return dp[m - 1][n - 1][0] % mod;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    int k;
    {
        A = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
        k = 3;
        auto r = so.numberOfPaths(A, k);
        cout << r << endl;
    }
    {
        A = {{0, 0}};
        k = 5;
        auto r = so.numberOfPaths(A, k);
        cout << r << endl;
    }
    {
        A = {{7, 3, 4, 9}, {2, 3, 6, 2}, {2, 3, 7, 0}};
        k = 1;
        auto r = so.numberOfPaths(A, k);
        cout << r << endl;
    }
    return 0;
}