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
        int idx;
    };
    struct Dis {
        int to;
        long long dist;
    };

   public:
    //  dijstra from both side
    // dist0N[x] + xy.weight + distN0[y] == dist0N[n-1]
    vector<bool> Dijkstra(int n, vector<vector<int>>& edges) {
        vector<vector<Edge>> g(n);
        int m = edges.size();

        for (int i = 0; i < m; ++i) {
            auto& e = edges[i];
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w, i});
            g[v].push_back({u, w, i});
        }

        auto cmp = [&](Dis& a, Dis& b) {
            return a.dist > b.dist;
        };  // minimum heap

        function<void(int, vector<long long>&)> dijkstra =
            [&](int s, vector<long long>& distTo) {
                distTo[s] = 0;
                priority_queue<Dis, vector<Dis>, decltype(cmp)> pq(cmp);
                pq.push({s, 0});
                while (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    int dist = top.dist, x = top.to;
                    if (dist > distTo[x])  // distTo[x] already updated.. this
                                           // is a stale data
                        continue;

                    for (auto [y, weight, _] : g[x]) {
                        int new_dist = dist + weight;
                        if (new_dist < distTo[y]) {
                            distTo[y] = new_dist;
                            pq.push({y, new_dist});
                        }
                    }
                }
            };
        vector<long long> distN(n, LLONG_MAX);

        dijkstra(0, distN);
        vector<bool> ret(m, 0);
        if (distN[n - 1] == LLONG_MAX)
            return ret;

        vector<long long> dist0(n, LLONG_MAX);
        dijkstra(n - 1, dist0);
        for (int i = 0; i < m; ++i) {
            int x = edges[i][0], y = edges[i][1], weight = edges[i][2];
            if (distN[x] == LLONG_MAX || dist0[y] == LLONG_MAX)
                continue;
            if (distN[x] > distN[y])  // short first
                swap(x, y);
            if (distN[x] + weight + dist0[y] == distN[n - 1])
                ret[i] = 1;
        }
        return ret;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        return Dijkstra(n, edges);
    }

    // dijstra from 0 and use BFS/DFS from n-1 to 0 to find all edges
    vector<bool> findAnswer1(int n, vector<vector<int>>& edges) {
        vector<vector<Edge>> g(n);
        int m = edges.size();

        for (int i = 0; i < m; ++i) {
            auto& e = edges[i];
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w, i});
            g[v].push_back({u, w, i});
        }

        auto cmp = [&](Dis& a, Dis& b) {
            return a.dist > b.dist;
        };  // minimum heap

        vector<long long> distTo(n, LLONG_MAX);
        priority_queue<Dis, vector<Dis>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});
        while (!pq.empty()) {
            auto top = pq.top();
            int dist = top.dist, x = top.to;
            pq.pop();
            if (dist > distTo[x])
                continue;
            for (auto& adj : g[x]) {
                int new_dist = dist + adj.weight;
                int y = adj.to;
                if (new_dist < distTo[y]) {
                    distTo[y] = new_dist;
                    pq.push({y, new_dist});
                }
            }
        }

        vector<bool> ret(m, 0);
        if (distTo[n - 1] == LLONG_MAX)
            return ret;
        vector<int> visited(n, 0);

        function<void(int)> dfs = [&](int y) {
            visited[y] = 1;
            for (auto& [to, weight, idx] : g[y]) {
                if (distTo[to] + weight != distTo[y])
                    continue;
                ret[idx] = true;
                if (!visited[to])
                    dfs(to);
            }
        };
        // dfs(n - 1);
        function<void(int)> bfs = [&](int start) {
            queue<int> que;
            que.push(start);
            visited[start] = 1;
            while (!que.empty()) {
                auto y = que.front();
                que.pop();
                // visited[y] = 1;
                for (auto [to, weight, idx] : g[y]) {
                    // equal adj edge
                    if (distTo[to] + weight == distTo[y]) {
                        ret[idx] = true;
                        if (!visited[to]) {
                            visited[to] = 1;
                            que.push(to);
                        }
                    }
                }
            }
        };
        bfs(n - 1);
        return ret;
    }
};
int main() {
    Solution so;

    return 0;
}