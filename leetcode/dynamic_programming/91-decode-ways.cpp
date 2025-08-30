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
    vector<int> memo;

   public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] - '0') {
                dp[i] = dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' &&
                (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
    int memo_dfs(string s) {
        int n = s.size();
        memo.resize(n, 0);
        int ret = dfs(s, 0);
        if (ret > 0)
            return ret;
        return 0;
    }
    int dfs(string& s, int i) {
        if (i == s.size())
            return 1;
        if (i > s.size())
            return 0;
        int ch = s[i] - '0';
        if (ch == 0)
            return 0;
        if (memo[i] > 0)
            return memo[i];
        int x = dfs(s, i + 1);
        int y = 0;
        int t = -26;
        if (i + 1 < s.size()) {
            t = s[i + 1] - '0';
        }
        int n = ch * 10 + t;
        if (n >= 10 && n <= 26)
            y = dfs(s, i + 2);

        return memo[i] = x + y;
    }
};
int main() {
    Solution so;
    string s;
    int count;
    {
        s = "12";
        count = so.numDecodings(s);
        cout << "s: " << s << ", count: " << count << endl;  // expect 2
    }
    {
        s = "226";
        count = so.numDecodings(s);
        cout << "s: " << s << ", count: " << count << endl;  // expect 3
    }
    {
        s = "0";
        count = so.numDecodings(s);
        cout << "s: " << s << ", count: " << count << endl;  // expect 0
    }
    {
        s = "06";
        count = so.numDecodings(s);
        cout << "s: " << s << ", count: " << count << endl;  // expect 0
    }
    {
        s = "10";
        count = so.numDecodings(s);
        cout << "s: " << s << ", count: " << count << endl;  // expect 1
    }
    {
        s = "27";
        count = so.numDecodings(s);
        cout << "s: " << s << ", count: " << count << endl;  // expect 1
    }
    return 0;
}