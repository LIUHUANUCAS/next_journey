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
    struct Edge {
        int to;
        int weight;
    };

   public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<Edge>> g(n + 1);
        for (auto& r : roads) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }
        vector<int> visited(n + 1);
        int ret = INT_MAX;
        function<void(int)> dfs = [&](int x) {
            visited[x] = 1;
            for (auto& adj : g[x]) {
                ret = min(ret, adj.weight);
                if (!visited[adj.to])
                    dfs(adj.to);
            }
        };
        dfs(1);
        return ret;
    }
};
int main() {
    Solution so;
    vector<vector<int>> roads;
    int n;
    {
        n = 4;
        roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
        cout << so.minScore(n, roads) << endl;  // expect 5
    }
    {
        n = 4;
        roads = {{1, 2, 100}, {2, 3, 100}, {2, 4, 100}, {1, 4, 100}};
        cout << so.minScore(n, roads) << endl;  // expect 100
    }
    {
        n = 3;
        roads = {{1, 2, 1}, {2, 3, 2}};
        cout << so.minScore(n, roads) << endl;  // expect 1
    }
    {
        n = 5;
        roads = {{1, 2, 3}, {1, 3, 4}, {3, 4, 5}, {4, 5, 6}};
        cout << so.minScore(n, roads) << endl;  // expect 3
    }
    {
        n = 5;
        roads = {{1, 2, -10}, {1, 3, -20}, {3, 4, -30}, {4, 5, -40}};
        cout << so.minScore(n, roads) << endl;  // expect -40
    }
    return 0;
}