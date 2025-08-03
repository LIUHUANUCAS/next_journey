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
    int minimumTotal(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> dp;
        dp.push_back({A[0]});
        for (int i = 1; i < m; ++i) {
            int size = A[i].size();
            dp.push_back(vector<int>(size, 0));
            for (int j = 0; j < size; ++j) {
                if (j == 0) {
                    dp[i][0] = dp[i - 1][0] + A[i][0];
                } else if (j + 1 == size) {
                    dp[i][size - 1] = dp[i - 1][size - 2] + A[i][size - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + A[i][j];
                }
            }
        }

        int ret = INT_MAX;
        for (auto it = dp.back().begin(); it != dp.back().end(); ++it) {
            ret = min(ret, *it);
        }
        return ret;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        auto r = so.minimumTotal(A);
        cout << r << endl;  // expect 11
    }
    {
        A = {{-10}};
        auto r = so.minimumTotal(A);
        cout << r << endl;  // expect -10
    }
    return 0;
}