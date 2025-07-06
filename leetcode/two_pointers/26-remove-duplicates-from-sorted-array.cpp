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
    int removeDuplicates(vector<int>& A) {
        int j = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] != A[j]) {
                ++j;
                if (i != j) {
                    A[j] = A[i];
                }
            }
        }
        return j + 1;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 1, 2};
        printvector(A);
        int out = so.removeDuplicates(A);
        printf("k:%d ", out);
        printvector(A);
    }
    {
        A = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        printvector(A);
        int out = so.removeDuplicates(A);
        printf("k:%d ", out);
        printvector(A);
    }
    {
        A = {1, 2};
        printvector(A);
        int out = so.removeDuplicates(A);
        printf("k:%d ", out);
        printvector(A);
    }
    {
        A = {1, 1, 1, 1, 1, 1, 1, 2};
        printvector(A);
        int out = so.removeDuplicates(A);
        printf("k:%d ", out);
        printvector(A);
    }
    return 0;
}