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
    int missingNumber(vector<int>& A) {
        int n = A.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret ^= (i + 1) ^ A[i];
        }
        return ret;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {0, 1, 2, 3, 4};
        auto r = so.missingNumber(A);
        printf("missingNumber: %d\n", r);
    }
    {
        A = {0, 1, 2, 4};
        auto r = so.missingNumber(A);
        printf("missingNumber: %d\n", r);
    }
    {
        A = {3, 0, 1};
        auto r = so.missingNumber(A);
        printf("missingNumber: %d\n", r);
    }
    {
        A = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        auto r = so.missingNumber(A);
        printf("missingNumber: %d\n", r);
    }
    return 0;
}