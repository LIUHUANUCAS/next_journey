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
        dp[0] = A[0];
        if (n == 1)
            return A[0];
        dp[1] = max(A[0], A[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
        }
        return dp[n - 1];
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 7, 9, 3, 1};
        auto r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 3, 1};
        auto r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 3};
        auto r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 3, 4};
        auto r = so.rob(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 3, 4, 5};
        auto r = so.rob(A);
        cout << r << endl;
    }
    return 0;
}