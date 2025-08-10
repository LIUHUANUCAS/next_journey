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
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }
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
        if (size[rootx] < size[rooty]) {
            size[rooty] += size[rootx];
            parent[rootx] = rooty;
        } else {
            size[rootx] += size[rooty];
            parent[rooty] = rootx;
        }
        return true;
    }

   public:
    vector<int> findRedundantConnection(vector<vector<int>>& A) {
        int n = A.size();
        init(n);
        vector<int> last_node;
        for (auto it = A.begin(); it != A.end(); ++it) {
            if (!union_set(it->at(0), it->at(1)))
                last_node = *it;
        }
        return last_node;
    }
};
int main() {
    Solution so;

    return 0;
}