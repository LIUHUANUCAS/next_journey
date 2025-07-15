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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> set;
        int max_len = 1;
        while (j < n) {
            set[s[j]] = j;
            j++;
            if (set.size() == k + 1) {
                int del_idx = j;
                for (auto& e : set) {
                    del_idx = min(del_idx, e.second);
                }
                set.erase(s[del_idx]);
                i = del_idx + 1;
            }
            max_len = max(max_len, j - i);
        }
        return max_len;
    }
};

int main() {
    Solution so;
    string s;
    {
        s = "eceba";
        int k = 2;
        cout << so.lengthOfLongestSubstringKDistinct(s, k) << endl;  // 3
    }
    {
        s = "aa";
        int k = 1;
        cout << so.lengthOfLongestSubstringKDistinct(s, k) << endl;  // 2
    }
    {
        s = "a";
        int k = 1;
        cout << so.lengthOfLongestSubstringKDistinct(s, k) << endl;  // 1
    }
    {
        s = "abcabcabc";
        int k = 2;
        cout << so.lengthOfLongestSubstringKDistinct(s, k) << endl;  // 2
    }
    return 0;
}