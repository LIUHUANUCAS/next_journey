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
    const vector<vector<int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

   public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (auto it = grid.begin(); it != grid.end(); ++it) {
            int x = it - grid.begin();
            for (auto i = it->begin(); i != it->end(); ++i) {
                int y = i - it->begin();
                if (grid[x][y] == '1') {
                    dfs(grid, x, y);
                    count++;
                }
            }
        }
        return count;
    }
    int dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (const auto& p : direction) {
            int x = i + p[0], y = j + p[1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
        return true;
    }
};
int main() {
    Solution so;
    vector<vector<char>> grid;
    {
        grid = {{'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}};
        auto r = so.numIslands(grid);
        cout << r << endl;  // expect 1
    }
    {
        grid = {{'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}};
        auto r = so.numIslands(grid);
        cout << r << endl;  // expect 3
    }
    return 0;
}