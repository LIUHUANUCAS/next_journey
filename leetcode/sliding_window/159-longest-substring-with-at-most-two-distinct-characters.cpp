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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> set;
        int max_len = 0;
        while (j < n) {
            char t = s[j++];
            set[t]++;
            while (set.size() > 2) {
                set[s[i]]--;
                if (set[s[i]] == 0) {
                    set.erase(s[i]);
                }
                i++;  // optimization: i can be moved forward if there's
                      // consecutive same characters
            }
            max_len = max(max_len, j - i);
        }
        return max_len;
    }
};
int main() {
    Solution so;

    return 0;
}