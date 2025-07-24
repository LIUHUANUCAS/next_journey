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
    int findLongestChain(vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        vector<int> tail;
        for (auto& p : A) {
            int x = p[0], y = p[1];
            if (tail.empty()) {
                tail.push_back(y);
            } else {
                auto lower = lower_bound(tail.begin(), tail.end(), x);
                if (lower == tail.end()) {
                    tail.push_back(y);
                } else {
                    *lower = min(y, *lower);
                }
            }
        }
        return tail.size();
    }
    int dp_lis(vector<vector<int>>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<int> dp(n + 1, 1);
        int max_len = 1;
        for (int i = 1; i < n; ++i) {
            int c = A[i][0], d = A[i][1];
            for (int j = i - 1; j >= 0; --j) {
                int a = A[j][0], b = A[j][1];
                if (b < c) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(dp[i], max_len);
        }
        return max_len;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    {
        A = {{1, 2}, {2, 3}, {3, 4}, {5, 6}};
        cout << "Input: A = ";
        printvector(A);
        int res = so.findLongestChain(A);
        cout << "Output: " << res << endl;
    }
    {
        A = {{1, 2}, {7, 8}, {4, 5}, {2, 3}};
        cout << "Input: A = ";
        printvector(A);
        int res = so.findLongestChain(A);
        cout << "Output: " << res << endl;
    }
    {
        A = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
        cout << "Input: A = ";
        printvector(A);
        int res = so.findLongestChain(A);
        cout << "Output: " << res << endl;
    }
    return 0;
}