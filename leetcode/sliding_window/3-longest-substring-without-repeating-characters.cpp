#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../header/data_type.h"

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int n = s.size();
        unordered_map<char, int> umap;
        int j = 0, max_len = 1;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                umap.erase(s[i - 1]);
            }
            while (j < n && umap.find(s[j]) == umap.end()) {
                umap[s[j]] = j;
                ++j;
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
        s = "abcabcbb";
        auto r = so.lengthOfLongestSubstring(s);
        cout << "s:" << s << " r:" << r << endl;
    }
    {
        s = "bbbbb";
        auto r = so.lengthOfLongestSubstring(s);
        cout << "s:" << s << " r:" << r << endl;
    }
    {
        s = "pwwkew";
        auto r = so.lengthOfLongestSubstring(s);
        cout << "s:" << s << " r:" << r << endl;
    }
    {
        s = "abc";
        auto r = so.lengthOfLongestSubstring(s);
        cout << "s:" << s << " r:" << r << endl;
    }
    return 0;
}