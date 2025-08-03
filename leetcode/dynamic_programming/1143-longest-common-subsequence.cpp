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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    Solution so;
    string text1, text2;
    {
        text1 = "abcde", text2 = "ace";
        cout << so.longestCommonSubsequence(text1, text2) << endl;  // 3
    }
    {
        text1 = "abc", text2 = "abc";
        cout << so.longestCommonSubsequence(text1, text2) << endl;  // 3
    }
    {
        text1 = "abc", text2 = "def";
        cout << so.longestCommonSubsequence(text1, text2) << endl;  // 0
    }
    return 0;
}