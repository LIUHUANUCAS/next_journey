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
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> cost;
        int n = chars.size();
        for (int i = 0; i < n; ++i) {
            cost[chars[i]] = vals[i];
        }
        auto get_value = [&](char ch) {
            if (cost.count(ch))
                return cost[ch];
            return ch - 'a' + 1;
        };
        int m = s.size();
        vector<int> values(m, 0);
        for (int i = 0; i < m; ++i) {
            values[i] = get_value(s[i]);
        }
        vector<int> dp(m, 0);
        dp[0] = values[0];
        for (int i = 1; i < m; ++i) {
            dp[i] = max(dp[i - 1] + values[i], values[i]);
        }
        return max(*max_element(dp.begin(), dp.end()), 0);
    }
};
int main() {
    Solution so;
    string s, chars;
    vector<int> vals;
    {
        s = "adaa", chars = "d", vals = {-1000};
        vals = {-1000};
        auto r = so.maximumCostSubstring(s, chars, vals);
        cout << r << endl;
    }
    {
        s = "abc", chars = "abc", vals = {-1, -1, -1};
        vals = {-1, -1, -1};
        auto r = so.maximumCostSubstring(s, chars, vals);
        cout << r << endl;
    }
    {
        s = "adaa", chars = "d", vals = {1000};
        vals = {1000};
        auto r = so.maximumCostSubstring(s, chars, vals);
        cout << r << endl;
    }
    return 0;
}