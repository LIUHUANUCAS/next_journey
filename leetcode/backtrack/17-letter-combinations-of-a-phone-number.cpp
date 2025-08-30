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
    vector<string> ret;

   public:
    vector<string> letterCombinations(string digits) {
        ret.clear();
        unordered_map<int, vector<char>> board = {
            {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};
        string path;
        backtrack(board, path, digits, 0);
        return ret;
    }

    void backtrack(unordered_map<int, vector<char>>& board,
                   string& path,
                   string& s,
                   int idx) {
        if (idx >= s.size()) {
            if (!path.empty())
                ret.push_back(path);
            return;
        }
        char ch = s[idx] - '0';

        auto array = board[ch];
        for (auto it = array.begin(); it != array.end(); ++it) {
            path.push_back(*it);
            backtrack(board, path, s, idx + 1);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    string digits;
    {
        digits = "23";
        auto r = so.letterCombinations(digits);
        cout << "digits=" << digits << endl;
        printvector(r);
    }
    {
        digits = "2";
        auto r = so.letterCombinations(digits);
        cout << "digits=" << digits << endl;
        printvector(r);
    }
    {
        digits = "";
        auto r = so.letterCombinations(digits);
        cout << "digits=" << digits << endl;
        printvector(r);
    }
    return 0;
}