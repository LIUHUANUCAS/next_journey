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
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m * n == 0)
            return n + m;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int v = dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]);
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = min(dp[i][j], v);
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution so;
    string s, t;
    {
        s = "horse", t = "ros";
        auto r = so.minDistance(s, t);
        cout << r << endl;
    }
    {
        s = "intention", t = "execution";
        auto r = so.minDistance(s, t);
        cout << r << endl;
    }
    {
        s = "a", t = "ab";
        auto r = so.minDistance(s, t);
        cout << r << endl;
    }
    return 0;
}