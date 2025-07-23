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
    int maximumLength(vector<int>& A, int k) {
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(k, 0));
        for (int i = 1; i < n; ++i) {
            int v = A[i] + A[i - 1];
            dp[i][v % k] = 2;
        }
        int max_len = 2;
        for (int i = 2; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int v = A[i] + A[j];
                int mod = v % k;
                if (dp[j][mod] > 0) {
                    dp[i][mod] = max(dp[i][mod], dp[j][mod] + 2);
                    max_len = max(max_len, dp[i][mod]);
                } else {
                    dp[i][mod] = max(dp[i][mod], 2);
                }
            }
        }
        return max_len;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 3, 4, 5};
        int k = 3;
        printvector(A);
        cout << "k: " << k << endl;
        auto res = so.maximumLength(A, k);
        cout << "res: " << res << endl;
    }
    {
        A = {3, 2, 1, 9, 1};
        int k = 6;
        printvector(A);
        cout << "k: " << k << endl;
        auto res = so.maximumLength(A, k);
        cout << "res: " << res << endl;
    }
    return 0;
}