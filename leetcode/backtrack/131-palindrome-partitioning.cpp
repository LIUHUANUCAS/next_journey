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
    vector<vector<string>> partition(string s) {
        // s[i,j] = s[i,k] card(*) s[k+1,j]   i<=k<j
        int n = s.size();
        vector<vector<string>> ret;
        vector<string> path;
        function<int(int, int)> is_palindrome = [&](int i, int j) {
            while (i < j) {
                if (s[i++] != s[j--])
                    return 0;
            }
            return 1;
        };
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ret.push_back(path);
                return;
            }
            for (int j = i; j < n; ++j) {
                if (is_palindrome(i, j)) {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ret;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "aab";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "a";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efe";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    {
        s = "efeaaaaaaaaaaaaaa";
        auto r = so.partition(s);
        printvector(r);
    }
    return 0;
}