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
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 1);
        int max_len = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; --j) {
                if (A[i] > A[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {10, 9, 2, 5, 3, 7, 101, 18};
        auto r = so.lengthOfLIS(A);
        cout << "r:" << r << endl;
    }
    {
        A = {0, 1, 0, 3, 2, 3};
        auto r = so.lengthOfLIS(A);
        cout << "r:" << r << endl;
    }
    {
        A = {7, 7, 7, 7, 7, 7, 7};
        auto r = so.lengthOfLIS(A);
        cout << "r:" << r << endl;
    }
    return 0;
}