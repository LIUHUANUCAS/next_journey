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
   public:
    double myPow(double x, int n) {
        long w = n;
        if (n < 0) {
            x = 1 / x;
            w = -w;
        }
        return dfs(x, w);
    }
    double dfs(double x, long n) {
        if (n <= 0)
            return 1;
        auto res = dfs(x * x, n / 2);
        if (n & 1) {
            return x * res;
        }

        return res;
    }
};

int main() {
    Solution so;

    return 0;
}