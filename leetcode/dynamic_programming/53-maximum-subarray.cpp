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
    int maxSubArray(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        dp[0] = A[0];
        int max_sum = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] + dp[i - 1] > A[i]) {
                dp[i] = A[i] + dp[i - 1];
            } else {
                dp[i] = A[i];
            }
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        auto r = so.maxSubArray(A);
        cout << "max_sum: " << r << endl;
    }
    {
        A = {5, 4, -1, 7, 8};
        auto r = so.maxSubArray(A);
        cout << "max_sum: " << r << endl;
    }
    {
        A = {1};
        auto r = so.maxSubArray(A);
        cout << "max_sum: " << r << endl;
    }
    return 0;
}