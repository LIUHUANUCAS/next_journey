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
    unordered_map<int, unordered_map<int, int>> memo;

   public:
    int uniquePaths2(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePaths1(int m, int n) {
        memo.clear();
        return dp(m, n);
    }
    int dp(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        if (memo.count(m) && memo.count(n))
            return memo[m][n];
        return memo[m][n] = dp(m - 1, n) + dp(m, n - 1);
    }
};
int main() {
    Solution so;

    return 0;
}