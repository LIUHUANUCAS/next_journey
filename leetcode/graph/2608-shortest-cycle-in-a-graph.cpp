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
    typedef pair<int, int> pii;

   public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> dis(n);
        function<int(int)> bfs = [&](int s) {
            int ret = INT_MAX;
            dis.assign(n, -1);
            dis[s] = 0;
            queue<pii> que;
            que.push({s, -1});
            while (!que.empty()) {
                auto [x, fa] = que.front();
                que.pop();
                for (int adj : g[x]) {
                    if (dis[adj] < 0) {  // first time to visit adj
                        dis[adj] = dis[x] + 1;
                        que.push({adj, x});
                    } else if (adj != fa) {  // find a cycle, so we need update
                                             // the cycle length
                        ret = min(ret, dis[adj] + dis[x] + 1);
                    }
                }
            }
            return ret;
        };
        int ret = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ret = min(ret, bfs(i));
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
int main() {
    Solution so;

    return 0;
}