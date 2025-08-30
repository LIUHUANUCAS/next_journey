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
    typedef pair<int, int> pii;
    int count;

   public:
    int totalNQueens(int n) {
        count = 0;
        vector<pii> path;
        backtrack(path, 0, n);
        return count;
    }
    void backtrack(vector<pii>& path, int row, int n) {
        if (row >= n) {
            count++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (valid_place(path, {row, col})) {
                path.push_back({row, col});
                backtrack(path, row + 1, n);
                path.pop_back();
            }
        }
    }
    bool valid_place(vector<pii>& path, pii point) {
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
        auto r = so.totalNQueens(4);
        cout << r << endl;  // Output: 2
    }
    {
        auto r = so.totalNQueens(5);
        cout << r << endl;  // Output: 10
    }
    return 0;
}