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
            if (n > 0)
                init(n);
        }
        void init(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
            count = n;
        }
        int components() { return count; }
        bool connected(int x, int y) { return find(x) == find(y); }
        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        bool union_set(int x, int y) {
            auto rootx = find(x);
            auto rooty = find(y);
            if (rootx == rooty)
                return false;
            if (size[x] < size[y]) {
                parent[rootx] = rooty;
                size[rooty] += size[rootx];
            } else {
                parent[rooty] = rootx;
                size[rootx] += size[rooty];
            }
            count--;
            return true;
        }
    };
    struct Edge {
        int u, v;
        int weight;
        int idx;
        bool operator<(const Edge& b) const { return this->weight > b.weight; }
        int other(int u) {
            if (u == this->u)
                return v;
            return this->u;
        }
    };

   public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& A) {
        vector<Edge> edges;
        int m = A.size();
        for (int i = 0; i < m; ++i) {
            int u = A[i][0], v = A[i][1], weight = A[i][2];
            edges.push_back({u, v, weight, i});
        }
        sort(edges.begin(), edges.end(),
             [](Edge& a, Edge& b) { return a.weight < b.weight; });
        int cost = 0;
        // find the real mst
        UnionFind uf(n);
        for (int i = 0; i < m; ++i) {
            if (uf.union_set(edges[i].u, edges[i].v)) {
                cost += edges[i].weight;
            }
        }
        vector<vector<int>> ret(2);
        // Edge edge;
        for (int i = 0; i < m; ++i) {
            UnionFind uf(n);
            int v = 0;
            // 1. exclude the edges[i] to build mst, if it's same weight then
            // it's a critical edge
            for (int j = 0; j < m; ++j) {
                auto e = edges[j];
                if (i != j &&
                    uf.union_set(e.u, e.v)) {  // not include edges[i].
                    v += e.weight;
                }
            }
            // can't build a mst, or the cost is larger than real mst, then it's
            // a cirtical edge
            if (uf.components() != 1 || (uf.components() == 1 && v > cost)) {
                ret[0].push_back({edges[i].idx});
                continue;
            }

            uf = UnionFind(n);
            // 2. include edges[i] to build mst, if cost is same with real mst,
            // then it's a pseudo-critical edge
            uf.union_set(edges[i].u, edges[i].v);
            v = edges[i].weight;
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.union_set(edges[j].u, edges[j].v)) {
                    v += edges[j].weight;
                }
            }

            if (v == cost) {  // cost is same with mst
                ret[1].push_back(edges[i].idx);
            }
        }

        return ret;
    }
};
int main() {
    Solution so;

    return 0;
}