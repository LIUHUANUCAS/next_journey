#include <cstdio>
#include <functional>
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
    int longestConsecutive(vector<int>& A) {
        if (A.empty())
            return 0;
        int n = A.size();
        vector<int> id(n), size(n, 1);
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }

        auto find = [&](int x) {
            while (id[x] != x) {
                // id[x] = id[id[x]];
                x = id[x];
            }
            return x;
        };

        auto union_set = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY)
                return;

            if (size[rootX] < size[rootY]) {
                id[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                id[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        };

        unordered_map<int, int> umap;
        for (int i = 0; i < n; ++i) {
            umap[A[i]] = i;
        }
        for (auto e : umap) {
            if (umap.find(e.first - 1) != umap.end()) {
                union_set(umap[e.first - 1], e.second);
            }
            if (umap.find(e.first + 1) != umap.end()) {
                union_set(umap[e.first + 1], e.second);
            }
        }

        int max_size = 1;
        for (int i = 0; i < n; ++i) {
            // printf("id[%d] = %d, size[%d] = %d, %d\n", i, id[i], i,
            // size[i],A[i]);
            if (id[i] == i) {  // Only consider root elements
                max_size = max(max_size, size[i]);
            }
        }
        return max_size;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {100, 4, 200, 1, 3, 2};
        int res = so.longestConsecutive(A);
        cout << res << endl;  // Output: 4
    }
    {
        A = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        int res = so.longestConsecutive(A);
        cout << res << endl;  // Output: 4
    }
    {
        A = {1, 0, 1, 2};
        int res = so.longestConsecutive(A);
        cout << res << endl;  // Output: 4
    }
    return 0;
}