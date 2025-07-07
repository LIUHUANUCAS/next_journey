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
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        vector<int> B(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0 && A[i] <= n) {
                B[A[i]] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (B[i] == 0) {
                return i;
            }
        }
        return n + 1;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 5, 3, 4};
        auto r = so.firstMissingPositive(A);
        printf("firstMissingPositive: %d\n", r);
    }
    {
        A = {3, 4, -1, 1};
        auto r = so.firstMissingPositive(A);
        printf("firstMissingPositive: %d\n", r);
    }
    {
        A = {7, 8, 9, 11, 12};
        auto r = so.firstMissingPositive(A);
        printf("firstMissingPositive: %d\n", r);
    }
    {
        A = {1, 1, 1, 2};
        auto r = so.firstMissingPositive(A);
        printf("firstMissingPositive: %d\n", r);
    }
    return 0;
}