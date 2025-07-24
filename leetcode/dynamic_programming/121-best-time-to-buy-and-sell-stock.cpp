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
    int maxProfit(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0), B(n, 0);
        for (int i = 1; i < n; ++i) {
            B[i - 1] = A[i] - A[i - 1];
        }
        dp[0] = max(B[0], 0);
        int max_value = dp[0];
        for (int i = 1; i < n - 1; ++i) {
            if (B[i] + dp[i - 1] > dp[i]) {
                dp[i] = dp[i - 1] + B[i];
            }
            max_value = max(max_value, dp[i]);
        }
        return max_value;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {7, 1, 5, 3, 6, 4};
        cout << "Input: A = ";
        printvector(A);
        cout << "Output: " << so.maxProfit(A) << endl;
    }
    {
        A = {7, 6, 4, 3, 1};
        cout << "Input: A = ";
        printvector(A);
        cout << "Output: " << so.maxProfit(A) << endl;
    }
    {
        A = {2, 1};
        cout << "Input: A = ";
        printvector(A);
        cout << "Output: " << so.maxProfit(A) << endl;
    }
    return 0;
}