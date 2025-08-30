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
    int maximumDetonation(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                long long x = A[i][0] - A[j][0], y = A[i][1] - A[j][1],
                          r = A[i][2];
                if (x * x + y * y <= r * r)
                    g[i].push_back(j);
            }
        }

        vector<int> visited(n, 0);
        function<int(int)> dfs = [&](int u) {
            visited[u] = 1;
            int node = 1;
            for (auto x : g[u]) {
                if (!visited[x]) {
                    node += dfs(x);
                }
            }
            return node;
        };
        int max_count = 1;
        for (int i = 0; i < n; ++i) {
            visited.assign(n, 0);
            max_count = max(dfs(i), max_count);
        }
        return max_count;
    }
};
int main() {
    Solution so;

    return 0;
}