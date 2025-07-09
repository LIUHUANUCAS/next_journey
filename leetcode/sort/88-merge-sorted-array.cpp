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
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while (i >= 0) {
            A[k--] = A[i--];
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};

int main() {
    Solution so;
    vector<int> A, B;
    {
        A = {1, 2, 3, 0, 0, 0};
        B = {2, 5, 6};
        so.merge(A, 3, B, 3);
        printvector(A);
    }
    {
        A = {1};
        B = {};
        so.merge(A, 1, B, 0);
        printvector(A);
    }
    {
        A = {0, 0};
        B = {1};
        so.merge(A, 1, B, 1);
        printvector(A);
    }

    return 0;
}