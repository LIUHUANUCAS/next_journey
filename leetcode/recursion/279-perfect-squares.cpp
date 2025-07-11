#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../header/data_type.h"

using namespace std;

class Solution {
    unordered_map<int, int> memo;

   public:
    int numSquares(int n) {
        memo.clear();
        return dfs(n);
    }
    int dfs(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (memo.count(n))
            return memo[n];
        int k = (int)sqrt(n);
        int len = n;
        for (int i = k; i >= 1; --i) {
            len = min(len, dfs(n - i * i) + 1);
        }
        memo[n] = len;
        return len;
    }
};

int main() {
    Solution so;
    int n;
    {
        n = 12;
        cout << so.numSquares(n) << endl;  // Output: 3 (4 + 4 + 4)
    }
    {
        n = 13;
        cout << so.numSquares(n) << endl;  // Output: 2 (4 + 9)
    }
    {
        n = 1;
        cout << so.numSquares(n) << endl;  // Output: 1
    }
    {
        n = 2;
        cout << so.numSquares(n) << endl;  // Output: 2 (1 + 1)
    }
    return 0;
}