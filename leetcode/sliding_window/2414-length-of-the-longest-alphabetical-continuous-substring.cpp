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
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int i = 0, j = 1, max_len = 1;
        while (j < n) {
            char c = s[j];
            int t = j++;
            if (c - s[t - 1] != 1) {
                i = t;
            } else {
                max_len = max(max_len, j - i);
            }
        }
        return max_len;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "abacaba";
        auto res = so.longestContinuousSubstring(s);
        cout << res << endl;  // Output: 2
    }
    {
        s = "abcde";
        auto res = so.longestContinuousSubstring(s);
        cout << res << endl;  // Output: 5
    }
    {
        s = "zab";
        auto res = so.longestContinuousSubstring(s);
        cout << res << endl;  // Output: 3
    }
    return 0;
}