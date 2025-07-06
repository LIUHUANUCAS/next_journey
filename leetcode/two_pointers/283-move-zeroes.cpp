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
    void moveZeroes(vector<int>& A) {
        int n = A.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != 0) {
                if (i != j) {
                    A[j] = A[i];
                    A[i] = 0;
                }
                ++j;
            }
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {0, 1, 0, 3, 12};
        so.moveZeroes(A);
        printvector(A);
    }
    {
        A = {0, 1, 0, 3, 12, 0, 1, 0};
        so.moveZeroes(A);
        printvector(A);
    }
    {
        A = {2, 1};
        so.moveZeroes(A);
        printvector(A);
    }
    return 0;
}