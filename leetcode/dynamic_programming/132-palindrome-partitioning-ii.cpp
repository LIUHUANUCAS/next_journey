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
    int minCut(string s) {
        int n = s.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
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
            }
        }
        vector<int> cut(n + 1, n - 1);
        cut[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (dp[0][i]) {
                cut[i] = 0;
            } else {
                for (int j = i; j >= 1; --j) {
                    if (dp[j][i]) {
                        cut[i] = min(cut[j - 1] + 1, cut[i]);
                    }
                }
            }
        }
        return cut[n - 1];
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "aab";
        cout << "input: " << s << endl;
        auto res = so.minCut(s);
        cout << "output: " << res << endl;
    }
    {
        s = "a";
        cout << "input: " << s << endl;
        auto res = so.minCut(s);
        cout << "output: " << res << endl;
    }
    {
        s = "ab";
        cout << "input: " << s << endl;
        auto res = so.minCut(s);
        cout << "output: " << res << endl;
    }
    {
        s = "abcde";
        cout << "input: " << s << endl;
        auto res = so.minCut(s);
        cout << "output: " << res << endl;
    }
    return 0;
}