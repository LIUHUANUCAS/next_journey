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
    unordered_map<int, int> visited;

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size())
            return false;
        visited.clear();
        vector<vector<int>> g(n + 1, vector<int>());
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g, 0);
        return visited.size() == n;
    }
    void dfs(vector<vector<int>>& g, int i) {
        visited[i]++;
        for (auto& adj : g[i]) {
            if (!visited.count(adj)) {
                dfs(g, adj);
            }
        }
    }
};
int main() {
    Solution so;
    vector<vector<int>> edges;
    {
        edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
        cout << so.validTree(5, edges) << endl;  // true
    }
    {
        edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}};
        cout << so.validTree(4, edges) << endl;  // false
    }
    {
        edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        cout << so.validTree(5, edges) << endl;  // true
    }
    {
        edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
        cout << so.validTree(6, edges) << endl;  // true
    }
    {
        edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
        cout << so.validTree(7, edges) << endl;  // true
    }
    {
        edges = {{0, 1}};
        cout << so.validTree(2, edges) << endl;  // true
    }
    {
        edges = {};
        cout << so.validTree(1, edges) << endl;  // true
    }
    {
        edges = {};
        cout << so.validTree(0, edges) << endl;  // false
    }
    return 0;
}