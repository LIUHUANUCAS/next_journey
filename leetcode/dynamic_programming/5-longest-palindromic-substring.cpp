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
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int len = 1, start_index = 0;

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i <= n - k; ++i) {
                int j = i + k - 1;

                if (k == 2) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }

                if (dp[i][j] && len < k) {
                    start_index = i;
                    len = k;
                }
            }
        }

        return s.substr(start_index, len);
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "babad";
        cout << "input: " << s << endl;
        auto res = so.longestPalindrome(s);
        cout << "output: " << res << endl;
    }
    {
        s = "cbbd";
        cout << "input: " << s << endl;
        auto res = so.longestPalindrome(s);
        cout << "output: " << res << endl;
    }
    {
        s = "a";
        cout << "input: " << s << endl;
        auto res = so.longestPalindrome(s);
        cout << "output: " << res << endl;
    }
    return 0;
}