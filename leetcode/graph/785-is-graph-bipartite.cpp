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
    vector<int> color;
    bool is_two_color;

   public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        visited.resize(n);
        color.resize(n);
        is_two_color = 1;
        for (int i = 0; i < n && is_two_color; ++i) {
            if (!visited[i])
                dfs(g, i);
        }
        return is_two_color;
    }
    void dfs(vector<vector<int>>& g, int s) {
        visited[s] = 1;
        for (auto adj : g[s]) {
            if (!visited[adj]) {
                color[adj] = !color[s];
                dfs(g, adj);
            } else if (color[adj] == color[s]) {
                is_two_color = false;
            }
        }
    }
};
int main() {
    Solution so;
    vector<vector<int>> g;
    {
        g = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
        cout << so.isBipartite(g) << endl;  // true
    }
    {
        g = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
        cout << so.isBipartite(g) << endl;  // false
    }
    {
        g = {{1}, {0, 3}, {3}, {1, 2}};
        cout << so.isBipartite(g) << endl;  // true
    }
    return 0;
}