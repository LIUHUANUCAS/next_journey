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
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        sort(A.begin(), A.end(), [](int a, int b) { return abs(a) <= abs(b); });
        for (int i = 0; i < n; ++i) {
            res[i] = A[i] * A[i];
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {-4, -1, 0, 3, 10};
        auto r = so.sortedSquares(A);
        printvector(r);
    }
    {
        A = {-7, -3, 2, 3, 11};
        auto r = so.sortedSquares(A);
        printvector(r);
    }
    {
        A = {0};
        auto r = so.sortedSquares(A);
        printvector(r);
    }
    {
        A = {1};
        auto r = so.sortedSquares(A);
        printvector(r);
    }
    {
        A = {-1};
    }
    {
        A = {-100, -99, -98, -98, -97, -91, -90, -87, -87, -80, -74, -73, -71,
             -69,  -66, -63, -63, -60, -60, -58, -57, -52, -49, -45, -41, -38,
             -32,  -31, -30, -30, -29, -28, -27, -27, -24, -21, -21, -21, -18,
             -13,  -12, -11, -10, -10, -9,  -8,  -5,  -5,  -5,  -4,  0,   0,
             0,    1,   2,   2,   2,   3,   3,   6,   16,  16,  22,  26,  28,
             30,   34,  35,  38,  39,  40,  45,  46,  47,  52,  53,  54,  56,
             56,   57,  59,  62,  62,  63,  65,  66,  67,  67,  69,  71,  75,
             79,   80,  83,  86,  88,  93,  94,  94,  99};
        auto r = so.sortedSquares(A);
        printvector(r);
    }
    return 0;
}