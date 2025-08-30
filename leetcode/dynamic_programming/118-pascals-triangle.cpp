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
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i].resize(i + 1, 1);
            dp[i][0] = 1;
            for (int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp;
    }
};
int main() {
    Solution so;

    return 0;
}