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
    unordered_map<string, bool> memo;
    // string key = to_string(i) + "_" + to_string(j);
   public:
    bool isMatch(string s, string p) {
        memo.clear();
        return dfs(s, 0, p, 0);
    }
    bool dfs(string& s, int i, string& p, int j) {
        int m = s.size(), n = p.size();
        if (i == m && j == n) return true;
        string key = to_string(i) + "_" + to_string(j);
        if (i == m) {
            return memo[key] = empty(p, j);
        }
        if (j == n) {
            return false;
        }

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // case1: s[i] == p[j]
        if (s[i] == p[j]) {
            if (j + 1 < n && p[j + 1] == '*') {
                // case1.1: s[i] == p[j] and p[j+1] == '*'
                memo[key] = dfs(s, i, p, j + 2) || dfs(s, i + 1, p, j + 2) ||
                            dfs(s, i + 1, p, j);
                return memo[key];
            }
            return memo[key] = dfs(s, i + 1, p, j + 1);
        }

        // case2: p[j] == '.'
        if (p[j] == '.') {
            if (j + 1 < n && p[j + 1] == '*') {
                return memo[key] = dfs(s, i, p, j + 2) ||
                                   dfs(s, i + 1, p, j + 2) ||
                                   dfs(s, i + 1, p, j);
            }
            //. without *
            return memo[key] = dfs(s, i + 1, p, j + 1);
        }

        // p[j] == '*'
        if (p[j] == '*') {
            if (j > 0 && s[i] == p[j - 1]) {
                // case2: s[i] == p[j-1]
                return memo[key] = dfs(s, i + 1, p, j) || dfs(s, i, p, j + 1) ||
                                   dfs(s, i + 1, p, j + 1);
            }

            if (j > 0 && s[i] != p[j - 1]) {
                return memo[key] = dfs(s, i, p, j + 1);
            }
            if (j == 0) return memo[key] = dfs(s, i, p, j + 1);
        }
        if (s[i] != p[j]) {
            if (j + 1 < n && p[j + 1] == '*') {
                return memo[key] = dfs(s, i, p, j + 2);
            }
            return memo[key] = false;
        }

        return memo[key] = s[i] == p[j] && dfs(s, i + 1, p, j + 1);
    }

    bool empty(string& p, int j) {
        int n = p.size();
        if (j >= n) return true;
        if (p[j] == '*') {
            return empty(p, j + 1);
        }
        if (p[j] != '*') {
            if (j + 1 < n && p[j + 1] == '*') return empty(p, j + 2);
            if (j + 1 < n && p[j + 1] != '*') {
                return false;
            }
        }
        return false;
    }

    bool isMatch2(string text, string pattern) {
        if (pattern.empty()) return text.empty();
        auto first_match =
            !text.empty() && (pattern[0] == text[0] || pattern[0] == '.');
        if (pattern.size() >= 2 && pattern[1] == '*') {
            return isMatch(text, pattern.substr(2)) ||
                   (first_match && isMatch(text.substr(1), pattern));
        } else {
            return (first_match && isMatch(text.substr(1), pattern.substr(1)));
        }
    }
};

int main() {
    Solution so;
    string s, p;
    {
        s = "aab";
        p = "c*a*b";
        cout << so.isMatch(s, p) << endl;  // true
    }
    {
        s = "mississippi";
        p = "mis*is*p*.";
        cout << so.isMatch(s, p) << endl;  // false
    }
    {
        s = "ab";
        p = ".*";
        cout << so.isMatch(s, p) << endl;  // true
    }
    {
        s = "a";
        p = ".*..a*";
        cout << so.isMatch(s, p) << endl;  // true
    }
    {
        s = "aab";
        p = "c*a*b";
        cout << so.isMatch(s, p) << endl;  // true
    }

    {
        s = "abb";
        p = "ab*c****";
        cout << so.isMatch(s, p) << endl;  // true
    }
    {
        s = "abcd";
        p = "abc*d";
        cout << so.isMatch(s, p) << endl;  // true
    }
    {
        s = "bbbba";
        p = ".*a*a";
        cout << so.isMatch(s, p) << endl;  // true
    }
    {
        s = "aaaaaaaaaaaaaaaaaaab";
        p = "a*a*a*a*a*a*a*a*a*a*";
        cout << so.isMatch(s, p) << endl;  // true
    }

    return 0;
}