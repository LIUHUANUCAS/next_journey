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
    int removeElement(vector<int>& A, int val) {
        int n = A.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != val) {
                if (i != j) {
                    A[j] = A[i];
                    A[i] = val;
                }
                ++j;
            }
        }
        return j;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {3, 2, 2, 3};
        int val = 3;
        printvector(A);
        int out = so.removeElement(A, val);
        printf("k:%d, val:%d ", out, val);
        printvector(A);
    }
    {
        A = {0, 1, 2, 2, 3, 0, 4, 2};
        int val = 2;
        printvector(A);
        int out = so.removeElement(A, val);
        printf("k:%d, val:%d ", out, val);
        printvector(A);
    }
    {
        A = {1};
        int val = 1;
        printvector(A);
        int out = so.removeElement(A, val);

        printf("k:%d, val:%d ", out, val);
        printvector(A);
    }
    {
        A = {1, 3, 2, 1};
        int val = 4;
        printvector(A);
        int out = so.removeElement(A, val);

        printf("k:%d, val:%d ", out, val);
        printvector(A);
    }
    return 0;
}