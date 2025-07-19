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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set;
        for (auto& str : wordDict) {
            set.insert(str);
        }
        vector<vector<int>> dp(n + 1);
        dp[0] = {0};
        for (int i = 1; i <= n; ++i) {
            dp[i] = {};
            for (int j = i - 1; j >= 0; --j) {
                if (!dp[j].empty()) {
                    string str(s.substr(j, i - j));
                    if (set.count(str)) {
                        dp[i].push_back(j);
                    }
                }
            }
        }
        if (dp[n].empty())
            return {};
        vector<vector<string>> allpath;
        vector<string> onepath;
        path(dp, s, n, onepath, allpath);
        return build_result(allpath);
    }

    vector<string> build_result(vector<vector<string>>& allpath) {
        vector<string> res;
        for (auto& onepath : allpath) {
            reverse(onepath.begin(), onepath.end());
            stringstream sst;
            for (auto it = onepath.begin(); it != onepath.end(); ++it) {
                sst << *it;
                if (it + 1 != onepath.end())
                    sst << ' ';
            }
            res.push_back(sst.str());
        }
        return res;
    }

    void path(vector<vector<int>>& dp,
              string& s,
              int i,
              vector<string>& onepath,
              vector<vector<string>>& allpath) {
        if (i == 0) {
            allpath.push_back(onepath);
            return;
        }

        for (auto j : dp[i]) {
            string str(s.substr(j, i - j));
            onepath.push_back(str);
            path(dp, s, j, onepath, allpath);
            onepath.pop_back();
        }
    }
};
int main() {
    Solution so;
    string s;
    vector<string> wordDict;

    {
        s = "catsanddog";
        wordDict = {"cat", "cats", "and", "sand", "dog"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);  // ["cats and dog","cat sand dog"]
    }
    {
        s = "pineapplepenapple";
        wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);  // ["pine apple pen apple","pineapple pen
                         // apple","pine applepen apple"]
    }
    {
        s = "catsandog";
        wordDict = {"cats", "dog", "sand", "and", "cat"};
        auto r = so.wordBreak(s, wordDict);
        printvector(r);  // []
    }
    return 0;
}