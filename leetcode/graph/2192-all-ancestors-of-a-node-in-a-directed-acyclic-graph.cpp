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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> rg(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            rg[v].push_back(u);
        }
        vector<int> visited(n);
        vector<vector<int>> ret(n);
        for (int i = 0; i < n; ++i) {
            visited.assign(n, 0);
            dfs(rg, visited, i);
            for (int j = 0; j < n; ++j) {
                if (visited[j] && i != j)
                    ret[i].push_back(j);
            }
        }
        return ret;
    }
    int dfs(vector<vector<int>>& g, vector<int>& visited, int s) {
        visited[s] = 1;
        for (auto adj : g[s]) {
            if (!visited[adj]) {
                dfs(g, visited, adj);
            }
        }
        return 1;
    }
};
int main() {
    Solution so;

    return 0;
}