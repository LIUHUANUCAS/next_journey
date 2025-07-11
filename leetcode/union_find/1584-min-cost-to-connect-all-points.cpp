#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../header/data_type.h"

using namespace std;

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> id(n);
        vector<int> size(n, 1);
        int count = n;
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
        auto find = [&](int x) {
            while (id[x] != x) {
                id[x] = id[id[x]];
                x = id[x];
            }
            return x;
        };
        auto union_set = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return false;
            if (size[rootX] < size[rootY]) {
                id[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                id[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            --count;
            return true;
        };
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]);
                edges.emplace_back(i, j, cost);
            }
        }
        int total_cost = 0;
        sort(edges.begin(), edges.end(),
             [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
                 return get<2>(a) < get<2>(b);
             });
        for (auto& e : edges) {
            int u = get<0>(e);
            int v = get<1>(e);
            int cost = get<2>(e);
            if (union_set(u, v)) {
                total_cost += cost;
                if (count == 1) {
                    break;
                }
            }
        }
        return total_cost;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
        cout << so.minCostConnectPoints(A) << endl;  // 20
    }
    {
        A = {{3, 12}, {-2, 5}, {-4, 1}};
        cout << so.minCostConnectPoints(A) << endl;
    }
    {
        A = {{0, 0}, {1, 1}, {1, 0}, {-1, 1}};
        cout << so.minCostConnectPoints(A) << endl;  // 4
    }
    {
        A = {{-1000000, -1000000}, {1000000, 1000000}};
        cout << so.minCostConnectPoints(A) << endl;  // 4000000
    }
    {
        A = {{-1000000, -1000000},
             {1000000, -1000000},
             {1000000, 1000000},
             {-1000000, 1000000}};
        cout << so.minCostConnectPoints(A) << endl;  // 8000000
    }

    return 0;
}