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
    int maxAbsoluteSum(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        dp[0] = A[0];
        int max_sum = max(A[0], INT_MIN);
        for (int i = 1; i < n; ++i) {
            if (A[i] + dp[i - 1] > A[i]) {
                dp[i] = dp[i - 1] + A[i];
            } else {
                dp[i] = A[i];
            }
            max_sum = max(max_sum, dp[i]);
        }
        int min_sum = min(INT_MAX, A[0]);
        for (int i = 1; i < n; ++i) {
            if (A[i] + dp[i - 1] < A[i]) {
                dp[i] = dp[i - 1] + A[i];
            } else {
                dp[i] = A[i];
            }
            min_sum = min(min_sum, dp[i]);
        }
        return max(abs(max_sum), abs(min_sum));
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, -3, 2, 3, -4};
        auto r = so.maxAbsoluteSum(A);
        cout << r << endl;  // 5
    }
    {
        A = {2, -5, 1, -4, 3, -2};
        auto r = so.maxAbsoluteSum(A);
        cout << r << endl;  // 8
    }
    {
        A = {-1, -2, -3};
        auto r = so.maxAbsoluteSum(A);
        cout << r << endl;  // 6
    }
    {
        A = {1, 2, 3};
        auto r = so.maxAbsoluteSum(A);
        cout << r << endl;  // 6
    }
    return 0;
}