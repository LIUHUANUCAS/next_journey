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
    int jump(vector<int>& A) {
        int n = A.size();
        int step = 0;
        int cur_right = 0, next_right = 0;
        for (int i = 0; i + 1 < n; ++i) {
            next_right = max(next_right, i + A[i]);
            if (i == cur_right) {
                cur_right = next_right;
                step++;
            }
        }
        return step;
    }
    int jump3(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, n + 1);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (A[j] + j >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
    int jump2(vector<int>& A) {
        int n = A.size();
        vector<int> memo(n, -1);
        // f(n-1) = 1 + min(f[i]) where A[i] + i >= n-1
        function<int(int)> dfs = [&](int s) {
            if (s == 0)
                return 0;
            if (memo[s] != -1)
                return memo[s];
            int mx = n + 1;
            for (int i = s - 1; i >= 0; --i) {
                if (A[i] + i >= s)
                    mx = min(mx, 1 + dfs(i));
            }
            return memo[s] = mx;
        };
        return dfs(n - 1);
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 3, 1, 1, 4};
        auto r = so.jump(A);
        cout << r << endl;
    }
    {
        A = {2, 3, 0, 1, 4};
        auto r = so.jump(A);
        cout << r << endl;
    }
    {
        A = {0};
        auto r = so.jump(A);
        cout << r << endl;
    }
    {
        A = {2, 1};
        auto r = so.jump(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 1, 1, 1};
        auto r = so.jump(A);
        cout << r << endl;
    }
    return 0;
}