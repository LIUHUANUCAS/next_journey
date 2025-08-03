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
   public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        vector<vector<int>> ret;
        ret.push_back(A[0]);
        int n = A.size();
        for (int i = 1; i < n; ++i) {
            auto pre = ret.back();
            if (pre[1] < A[i][0]) {
                ret.push_back(A[i]);
            } else {
                int v = ret.back()[1];
                ret.back()[1] = max(v, A[i][1]);
            }
        }
        return ret;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        auto r = so.merge(A);
        printvector(r);
    }
    {
        A = {{1, 4}, {4, 5}};
        auto r = so.merge(A);
        printvector(r);
    }
    {
        A = {{1, 4}, {0, 4}};
        auto r = so.merge(A);
        printvector(r);
    }
    {
        A = {{1, 4}, {2, 3}};
        auto r = so.merge(A);
        printvector(r);
    }
    return 0;
}