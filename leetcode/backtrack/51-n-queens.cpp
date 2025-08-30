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
    typedef pair<int, int> ppi;

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<vector<ppi>> path;
        vector<ppi> place;
        backtrack(path, place, 0, n);
        for (auto& e : path) {
            vector<string> onepath(n, string(n, '.'));
            for (auto& p : e) {
                auto [x, y] = p;
                onepath[x][y] = 'Q';
            }
            ret.push_back(onepath);
        }
        return ret;
    }
    void backtrack(vector<vector<ppi>>& ret,
                   vector<ppi>& path,
                   int row,
                   int n) {
        if (row >= n) {
            ret.push_back(path);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (valid_place(path, {row, col})) {
                path.push_back({row, col});
                backtrack(ret, path, row + 1, n);
                path.pop_back();
            }
        }
    }
    bool valid_place(vector<ppi>& path, ppi point) {
        if (path.empty())
            return true;
        auto [x_, y_] = point;
        for (auto& p : path) {
            auto [x, y] = p;
            if (x == x_ || y == y_ || (abs(x - x_) == abs(y - y_)))
                return false;
        }
        return true;
    }
};
int main() {
    Solution so;
    {
        auto r = so.solveNQueens(4);
        printvector(r);
    }
    {
        auto r = so.solveNQueens(1);
        printvector(r);
    }
    {
        auto r = so.solveNQueens(5);
        printvector(r);
    }
    // {
    //     auto r = so.solveNQueens(9);
    //     printvector(r);
    // }
    return 0;
}