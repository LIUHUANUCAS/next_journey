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
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 1;  // 0 A[i] < A[i+1]
        dp[0][1] = 1;  // 1 A[i] > A[i+1];
        int max_len = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = 1;
            } else if (A[i] < A[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = 1;
            } else {
                dp[i] = {1, 1};
            }
            max_len = max(max_len, max(dp[i][0], dp[i][1]));
        }
        return max_len;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {9, 4, 2, 10, 7, 8, 8, 1, 9};
        auto r = so.maxTurbulenceSize(A);
        cout << r << endl;  // 5
    }
    {
        A = {4, 8, 12, 16};
        auto r = so.maxTurbulenceSize(A);
        cout << r << endl;  // 2
    }
    {
        A = {100};
        auto r = so.maxTurbulenceSize(A);
        cout << r << endl;  // 1
    }
    {
        A = {9, 9};
        auto r = so.maxTurbulenceSize(A);
        cout << r << endl;  // 1
    }
    return 0;
}