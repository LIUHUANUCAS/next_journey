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
    unordered_map<int, int> memo;

   public:
    bool canJump(vector<int>& A) {
        int mx = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (i > mx)
                return false;
            mx = max(mx, i + A[i]);
        }
        return true;
    }
    bool canJump2(vector<int>& A) {
        if (A.size() <= 1)
            return true;
        memo.clear();
        return dfs(A, 0);
    }
    bool dfs(vector<int>& A, int i) {
        int n = A.size();
        if (i >= n - 1)
            return true;

        if (memo.count(i))
            return memo[i];

        for (int j = A[i]; j >= 1; --j) {
            int idx = j + i;
            if (dfs(A, idx)) {
                return memo[i] = true;
            }
        }
        return memo[i] = false;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 3, 1, 1, 4};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    {
        A = {3, 2, 1, 0, 4};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    {
        A = {0};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    {
        A = {2, 0};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    {
        A = {2, 5, 0, 0};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    {
        A = {1, 2, 3};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    {
        A = {2, 0, 0};
        auto r = so.canJump(A);
        cout << r << endl;
    }
    return 0;
}