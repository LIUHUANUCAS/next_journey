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

   public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, int> ch2id;
        for (auto& e : equations) {
            int u = e[0], v = e[3];
            if (!ch2id.count(u)) {
                ch2id[u] = ch2id.size();
            }
            if (!ch2id.count(v)) {
                ch2id[v] = ch2id.size();
            }
        }
        int n = ch2id.size();
        UnionFind uf(n);
        for (auto& e : equations) {
            int u = e[0], v = e[3];
            if (e[1] == '=') {
                uf.union_set(ch2id[u], ch2id[v]);
            }
        }
        for (auto& e : equations) {
            int u = e[0], v = e[3];
            int x = ch2id[u], y = ch2id[v];
            if (e[1] == '!' && uf.find(x) == uf.find(y)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution so;
    vector<string> equations;
    {
        equations = {"a==b", "b!=a"};
        cout << so.equationsPossible(equations) << endl;  // false
    }
    {
        equations = {"b==a", "a==b"};
        cout << so.equationsPossible(equations) << endl;  // true
    }
    {
        equations = {"a==b", "b==c", "a==c"};
        cout << so.equationsPossible(equations) << endl;  // true
    }
    {
        equations = {"a==b", "b!=c", "c==a"};
        cout << so.equationsPossible(equations) << endl;  // false
    }
    {
        equations = {"c==c", "b==d", "x!=z"};
        cout << so.equationsPossible(equations) << endl;  // true
    }
    return 0;
}