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
    unordered_map<int, int> memo;

   public:
    int numSquares(int n) {
        // const int N = 10000;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            for (int j = i * i; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
    int numSquares1(int n) {
        memo.clear();
        return dfs(n);
    }
    int dfs(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (memo.count(n))
            return memo[n];
        int k = (int)sqrt(n);
        int len = n;
        for (int i = k; i >= 1; --i) {
            len = min(len, dfs(n - i * i) + 1);
        }
        memo[n] = len;
        return len;
    }
};
int main() {
    Solution so;
    int n;
    {
        n = 12;
        auto r = so.numSquares(n);
        cout << r << endl;
    }
    {
        n = 13;
        auto r = so.numSquares(n);
        cout << r << endl;
    }
    {
        n = 7168;
        auto r = so.numSquares(n);
        cout << r << endl;
    }
    {
        n = 10000;
        auto r = so.numSquares(n);
        cout << r << endl;
    }
    return 0;
}