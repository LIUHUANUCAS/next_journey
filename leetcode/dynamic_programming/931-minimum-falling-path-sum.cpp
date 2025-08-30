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
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int t = A[i - 1][j - 1];
                vector<int> tmp = {dp[i - 1][j]};
                if (j + 1 <= n)
                    tmp.push_back(dp[i - 1][j + 1]);
                if (j - 1 > 0)
                    tmp.push_back(dp[i - 1][j - 1]);
                dp[i][j] = *min_element(tmp.begin(), tmp.end()) + t;
            }
        }
        return *min_element(dp[m].begin() + 1, dp[m].end());
    }
};
int main() {
    Solution so;

    return 0;
}