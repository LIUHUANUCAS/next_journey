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
int main() {
    return 0;
}