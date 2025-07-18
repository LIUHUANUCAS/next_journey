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
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 1)
                break;
            else
                dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (A[0][j] == 1)
                break;
            else
                dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (A[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main() {
    Solution so;

    return 0;
}