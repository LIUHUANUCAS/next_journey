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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> id(n);
        vector<int> size(n, 1);
        for (int i = 0; i < n; ++i) id[i] = i;
        auto find = [&](int x) {
            while (x != id[x]) {
                id[x] = id[id[x]];
                x = id[x];
            }
            return x;
        };
        auto union_set = [&](int x, int y) {
            auto rootX = find(x);
            auto rootY = find(y);
            if (rootX == rootY) return;
            if (size[rootX] <= size[rootY]) {
                id[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                id[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) union_set(i, j);
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (id[i] == i) count++;
        }
        return count;
    }
};

int main() {
    Solution so;

    return 0;
}