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
    unordered_map<string, int> word_count;
    unordered_map<int, int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        word_count.clear();
        memo.clear();
        for (auto& s : wordDict)
            word_count[s]++;
        return dfs(s, 0);
    }
    bool dfs(string& s, int start) {
        int n = s.size();
        if (start == n)
            return true;
        if (memo.count(start))
            return memo[start];
        for (int i = start; i < n; ++i) {
            string word(s.substr(start, i - start + 1));
            if (word_count.count(word) && dfs(s, i + 1)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
};
int main() {
    Solution so;
    string s;
    vector<string> wordDict;
    {
        s = "leetcode";
        wordDict = {"leet", "code"};
        auto res = so.wordBreak(s, wordDict);
        cout << "res:" << res << endl;
    }
    {
        s = "applepenapple";
        wordDict = {"apple", "pen"};
        auto res = so.wordBreak(s, wordDict);
        cout << "res:" << res << endl;
    }
    return 0;
}