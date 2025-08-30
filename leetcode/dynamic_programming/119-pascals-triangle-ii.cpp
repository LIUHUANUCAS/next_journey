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
    vector<int> getRow(int n) {
        vector<int> dp(n + 1, 1), t(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                t[j] = dp[j - 1] + dp[j];
            }
            swap(t, dp);
        }
        return dp;
    }
};
int main() {
    Solution so;

    return 0;
}