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
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1)
            return strs[0];
        return divide_conquer(strs, 0, n - 1);
    }
    string longestCommonPrefix2(vector<string>& strs) {
        int n = strs.size();
        if (n == 1)
            return strs[0];
        int len = 0, min_len = INT_MAX;
        string prefix = strs[0];
        for (int i = 1; i < n; ++i) {
            len = common_len(strs[i], prefix);
            if (len == 0)
                return "";
            min_len = min(len, min_len);
            prefix = strs[i].substr(0, min_len);
        }
        return strs.back().substr(0, min_len);
    }
    int common_len(string& s, string& t) {
        int n = min(s.size(), t.size());
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i])
                return i;
        }
        return n;
    }
    string divide_conquer(vector<string>& strs, int lo, int hi) {
        if (lo == hi)
            return strs[lo];
        int mid = (lo + hi) / 2;
        string left = divide_conquer(strs, lo, mid);
        string right = divide_conquer(strs, mid + 1, hi);
        int len = common_len(left, right);
        return strs[lo].substr(0, len);
    }
};
int main() {
    Solution so;
    vector<string> strs;
    {
        strs = {"flower", "flow", "flight"};
        cout << so.longestCommonPrefix(strs) << endl;  // "fl"
    }
    {
        strs = {"dog", "racecar", "car"};
        cout << so.longestCommonPrefix(strs) << endl;  // ""
    }
    {
        strs = {"a"};
        cout << so.longestCommonPrefix(strs) << endl;  // "a"
    }
    {
        strs = {"ab", "a"};
        cout << so.longestCommonPrefix(strs) << endl;  // "a"
    }
    return 0;
}