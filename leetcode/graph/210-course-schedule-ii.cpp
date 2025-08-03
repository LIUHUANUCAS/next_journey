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
    vector<int> visited;
    vector<int> path;

   public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        visited.resize(n);
        path.clear();
        vector<vector<int>> g(n);
        for (const auto& e : prerequisites) {
            int u = e[1], v = e[0];
            g[u].push_back(v);
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && !dfs(g, i))
                return {};
        }
        reverse(path.begin(), path.end());
        return path;
    }
    bool dfs(vector<vector<int>>& g, int i) {
        visited[i] = 1;
        for (const auto adj : g[i]) {
            if (!visited[adj] && !dfs(g, adj)) {
                return false;
            } else if (visited[adj] == 1)
                return false;
        }
        visited[i] = 2;
        path.push_back(i);
        return true;
    }
};
int main() {
    Solution so;
    vector<vector<int>> prerequisites;
    {
        prerequisites = {{1, 0}};
        auto r = so.findOrder(2, prerequisites);
        printvector(r);  // expect [0, 1]
    }
    {
        prerequisites = {{1, 0}, {0, 1}};
        auto r = so.findOrder(2, prerequisites);
        printvector(r);  // expect []
    }
    {
        prerequisites = {{1, 0}, {2, 1}, {3, 2}};
        auto r = so.findOrder(4, prerequisites);
        printvector(r);  // expect [0, 1, 2, 3]
    }
    {
        prerequisites = {{1, 0}, {2, 1}, {3, 2}, {4, 3}};
        auto r = so.findOrder(5, prerequisites);
        printvector(r);  // expect [0, 1, 2, 3, 4]
    }
    return 0;
}