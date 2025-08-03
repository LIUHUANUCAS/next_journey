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
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        if (m + n != t)
            return false;
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[n][m];
    }
};
int main() {
    Solution so;
    string s1, s2, s3;
    {
        s1 = "aabcc";
        s2 = "dbbca";
        s3 = "aadbbcbcac";
        cout << so.isInterleave(s1, s2, s3) << endl;  // true
    }
    {
        s1 = "aabcc";
        s2 = "dbbca";
        s3 = "aadbbbaccc";
        cout << so.isInterleave(s1, s2, s3) << endl;  // false
    }
    {
        s1 = "";
        s2 = "";
        s3 = "";
        cout << so.isInterleave(s1, s2, s3) << endl;  // true
    }
    return 0;
}