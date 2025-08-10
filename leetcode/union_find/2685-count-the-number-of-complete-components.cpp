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
    vector<int> parent;
    vector<int> size;
    void init(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void union_set(int x, int y) {
        auto rootx = find(x);
        auto rooty = find(y);
        if (rootx == rooty)
            return;
        if (size[x] < size[y]) {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        } else if (size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }

    vector<int> visited;
    vector<int> id;
    int count;

   public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g;
        g.resize(n);
        visited.resize(n);
        id.resize(n);
        count = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(g, i);
                count++;
            }
        }
        unordered_map<int, pair<int, int>>
            node_edge;  // node_id ->{node_count,edge}

        for (int i = 0; i < n; ++i) {
            int node_idx = id[i];
            node_edge[node_idx].first++;
        }
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int node_idx = id[u];
            node_edge[node_idx].second++;
        }
        int ret = 0;
        for (auto& p : node_edge) {
            int node_num = p.second.first;
            int edge = p.second.second;
            if (node_num * (node_num - 1) / 2 == edge)
                ret++;
        }
        return ret;
    }

    void dfs(vector<vector<int>>& g, int s) {
        visited[s] = 1;
        id[s] = count;
        for (auto adj : g[s]) {
            if (!visited[adj]) {
                dfs(g, adj);
            }
        }
    }
    int countCompleteComponents1(int n, vector<vector<int>>& edges) {
        init(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            union_set(u, v);
        }
        vector<int> edge_set(n, 0);

        for (auto& edge : edges) {
            edge_set[find(edge[0])]++;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                int x = size[i];
                int all_edges = x * (x - 1) / 2;
                if (edge_set[i] == all_edges)
                    count++;
            }
        }
        return count;
    }
};
int main() {
    Solution so;
    vector<vector<int>> edges;
    {
        edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}};
        int n = 6;
        cout << so.countCompleteComponents(n, edges) << endl;  // 2
    }
    {
        edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {4, 5}, {5, 6}, {6, 3}};
        int n = 7;
        cout << so.countCompleteComponents(n, edges) << endl;  // 1
    }
    {
        edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4},
                 {4, 5}, {5, 6}, {6, 3}, {7, 8}};
        int n = 9;
        cout << so.countCompleteComponents(n, edges) << endl;  // 2
    }
    return 0;
}