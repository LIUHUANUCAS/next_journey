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
    struct UnionFind {
        vector<int> parent;
        vector<int> size;
        int count;
        UnionFind(int n = 0) {
            if (n > 0) {
                init(n);
            }
        }
        void init(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
            count = n;
        }
        bool connected(int x, int y) { return find(x) == find(y); }
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
            } else {
                parent[rooty] = rootx;
                size[rootx] += size[rooty];
            }
            count--;
        }
    };
    struct Edge {
        int u, v;
        int weight;
        bool operator<(const Edge& b) const { return this->weight > b.weight; }
        int other(int u) {
            if (u == this->u)
                return v;
            return this->u;
        }
    };

   public:
    vector<Edge> Prim(vector<vector<Edge>>& g) {
        int n = g.size();
        vector<int> marked(n, 0);
        priority_queue<Edge> pq;

        auto visit = [&](int u) {
            if (!marked[u]) {
                marked[u] = 1;
                for (auto adj : g[u]) {
                    int other = adj.other(u);
                    if (!marked[other])
                        pq.push(adj);
                }
            }
        };

        for (auto e : g[0]) {
            pq.push(e);
        }
        marked[0] = 1;
        vector<Edge> mst;
        Edge edge;
        while (!pq.empty() && mst.size() < n) {
            edge = pq.top();
            pq.pop();
            if (marked[edge.u] && marked[edge.v])
                continue;
            mst.push_back(edge);
            if (!marked[edge.u])
                visit(edge.u);
            if (!marked[edge.v])
                visit(edge.v);
        }
        return mst;
    }
    int minCostToSupplyWater(int n,
                             vector<int>& wells,
                             vector<vector<int>>& pipes) {
        vector<vector<Edge>> g(n + 1);
        Edge edge;
        vector<Edge> edges;
        for (int i = 0; i < wells.size(); ++i) {
            edge = {0, i + 1, wells[i]};
            g[0].push_back(edge);
            edges.push_back(edge);
        }
        for (auto& e : pipes) {
            int u = e[0], v = e[1], weight = e[2];
            edge = {u, v, weight};
            edges.push_back(edge);
            g[u].push_back(edge);
            g[v].push_back(edge);
        }

        // vector<Edge> mst = Prim(g);
        vector<Edge> mst = Krushkal(n, edges);
        int cost = 0;
        for (auto edge : mst)
            cost += edge.weight;
        return cost;
    }

    vector<Edge> Krushkal(int n, vector<Edge>& edges) {
        UnionFind uf(n + 1);
        priority_queue<Edge> pq;
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            Edge edge(*it);
            pq.push(edge);
        }

        vector<Edge> mst;
        while (!pq.empty() && mst.size() < n) {
            auto x = pq.top();
            pq.pop();
            if (uf.connected(x.u, x.v))
                continue;
            uf.union_set(x.u, x.v);
            mst.push_back(x);
        }
        return mst;
    }
};
int main() {
    Solution so;
    vector<int> wells;
    vector<vector<int>> pipes;
    int n;
    {
        n = 3;
        wells = {1, 2, 2};
        pipes = {{1, 2, 1}, {2, 3, 1}};
        cout << so.minCostToSupplyWater(n, wells, pipes) << endl;  // 3
    }
    {
        n = 5;
        wells = {1, 2, 2, 1, 2};
        pipes = {{1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};
        cout << so.minCostToSupplyWater(n, wells, pipes) << endl;  // 6
    }
    {
        n = 5;
        wells = {1, 2, 2, 1, 2};
        pipes = {{1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 10}};
        cout << so.minCostToSupplyWater(n, wells, pipes) << endl;  // 7
    }
    return 0;
}