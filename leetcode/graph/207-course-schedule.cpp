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

   public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        visited.resize(n);
        vector<vector<int>> g(n);
        for (const auto& e : prerequisites) {
            int u = e[1], v = e[0];
            g[u].push_back(v);
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && !dfs(g, i))
                return false;
        }
        return true;
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
        return true;
    }
    bool canFinish1(int n, vector<vector<int>>& prerequisites) {
        // BFS
        vector<int> indegree(n, 0);
        vector<vector<int>> g(n);
        for (auto& e : prerequisites) {
            int u = e[1], v = e[0];
            indegree[v]++;

            g[u].push_back(v);
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                que.push(i);
        }
        int count = 0;
        while (!que.empty()) {
            auto x = que.front();
            que.pop();
            count++;
            for (auto adj : g[x]) {
                if (--indegree[adj] == 0) {
                    que.push(adj);
                }
            }
        }
        return count == n;
    }
};
int main() {
    Solution so;

    return 0;
}