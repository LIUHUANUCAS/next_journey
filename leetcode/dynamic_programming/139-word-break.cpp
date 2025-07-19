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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // unordered_map<string, int> umap;
        unordered_set<string> set;
        for (auto& str : wordDict) {
            set.insert(str);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // empty string is cuttable
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string str(s.substr(j, i - j));
                    dp[i] = set.count(str);
                    if (dp[i])
                        break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution so;
    string s;
    vector<string> wordDict;

    {
        s = "leetcode";
        wordDict = {"leet", "code"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;  // true
    }
    {
        s = "applepenapple";
        wordDict = {"apple", "pen"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;  // true
    }
    {
        s = "catsandog";
        wordDict = {"cats", "dog", "sand", "and", "cat"};
        auto r = so.wordBreak(s, wordDict);
        cout << r << endl;  // false
    }
    return 0;
}