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
    int orangesRotting(vector<vector<int>>& A) {
        queue<pair<int, int>> que;
        int m = A.size(), n = A[0].size();
        int fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 2)
                    que.push({i, j});
                if (A[i][j] == 1)
                    fresh++;
            }
        }

        // 1. no rotten orange
        // 2. fresh orange count
        // 3. no fresh and rotten orange -> return 0;

        if (que.empty()) {
            if (fresh)
                return -1;
            return 0;
        }
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        function<vector<pair<int, int>>(int, int)> get_adj = [&](int x, int y) {
            vector<pair<int, int>> ret;
            for (auto [u, v] : directions) {
                int i = x + u, j = y + v;
                if (i >= 0 && i < m && j >= 0 && j < n)
                    ret.push_back({i, j});
            }
            return ret;
        };
        int count = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = que.front();
                que.pop();
                auto adj = get_adj(x, y);
                for (auto [u, v] : adj) {
                    if (A[u][v] == 1) {
                        A[u][v] = 2;
                        fresh--;
                        que.push({u, v});
                    }
                }
            }
            ++count;
        }
        if (fresh == 0)
            return count - 1;
        return -1;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
        auto r = so.orangesRotting(A);
        cout << "r:" << r << endl;
    }
    {
        A = {{2, 1, 1}, {0, 1, 0}, {1, 0, 1}};
        auto r = so.orangesRotting(A);
        cout << "r:" << r << endl;
    }
    {
        A = {{0, 2}};
        auto r = so.orangesRotting(A);
        cout << "r:" << r << endl;
    }
    {
        A = {{0}};
        auto r = so.orangesRotting(A);
        cout << "r:" << r << endl;
    }
    {
        A = {{1}};
        auto r = so.orangesRotting(A);
        cout << "r:" << r << endl;
    }
    return 0;
}