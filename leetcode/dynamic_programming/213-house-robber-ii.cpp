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
    int rob(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        if (n == 1)
            return A[0];
        if (n == 2)
            return max(A[0], A[1]);
        dp[1] = A[1];
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + A[i], dp[i - 1]);
        }
        int v = dp[n - 1];
        dp = vector<int>(n + 1, 0);
        dp[0] = A[0];
        dp[1] = max(A[0], A[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
        }
        return max(dp[n - 2], v);
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 3, 2};
        cout << "input: ";
        printvector(A);
        cout << "output: " << so.rob(A) << endl;
    }
    {
        A = {1, 2, 3, 1};
        cout << "input: ";
        printvector(A);
        cout << "output: " << so.rob(A) << endl;
    }
    {
        A = {1, 2, 3};
        cout << "input: ";
        printvector(A);
        cout << "output: " << so.rob(A) << endl;
    }
    {
        A = {1, 2, 3, 4, 5};
        cout << "input: ";
        printvector(A);
        cout << "output: " << so.rob(A) << endl;
    }
    return 0;
}