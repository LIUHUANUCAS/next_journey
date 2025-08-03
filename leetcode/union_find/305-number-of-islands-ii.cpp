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
    const vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> parent;
    vector<int> size;
    int count;
    void init_union_set(int m, int n) {
        parent.resize(m * n, -1);
        size.resize(m * n, 1);
    }
    void add(int x) {
        if (parent[x] != -1)
            return;
        parent[x] = x;
        size[x] = 1;
        count++;
    }
    int find(int x) {
        if (parent[x] == -1) {
            return -1;
        }
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void union_set(int rootX, int rootY) {
        int x = find(rootX);
        int y = find(rootY);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
        count--;
    }
    int count_set() { return count; }

   public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& pos) {
        init_union_set(m, n);
        vector<int> ret;
        for (const auto& p : pos) {
            int i = p[0], j = p[1];
            int x = i * n + j;
            if (find(x) == -1) {
                add(x);
            }
            for (const auto& d : directions) {
                int a = i + d[0], b = j + d[1];
                if (a >= 0 && a < m && b >= 0 && b < n) {
                    int y = a * n + b;
                    if (find(y) != -1) {
                        union_set(x, y);
                    }
                }
            }
            ret.push_back(count_set());
        }
        return ret;
    }
};
int main() {
    Solution so;

    return 0;
}