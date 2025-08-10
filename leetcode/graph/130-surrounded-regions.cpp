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
    int m, n;

   public:
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n - 1; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& g, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] != 'O')
            return;
        g[x][y] = 'A';
        dfs(g, x + 1, y);
        dfs(g, x - 1, y);
        dfs(g, x, y + 1);
        dfs(g, x, y - 1);
    }
};
int main() {
    Solution so;
    vector<vector<char>> board;
    {
        board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
        };
        so.solve(board);
        printvector(board);
    }
    {
        board = {
            {'O', 'O', 'O', 'O'},
            {'O', 'X', 'X', 'O'},
            {'O', 'X', 'X', 'O'},
            {'O', 'O', 'O', 'O'},
        };
        so.solve(board);
        printvector(board);
    }
    {
        board = {
            {'X'},
        };
        so.solve(board);
        printvector(board);
    }
    {
        board = {
            {'X', 'X'},
            {'X', 'X'},
        };
        so.solve(board);
        printvector(board);
    }
    return 0;
}