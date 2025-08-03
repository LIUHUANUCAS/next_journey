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
   public:
    int removeDuplicates(vector<int>& A) {
        int n = A.size();
        int count = 1, j = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] == A[j]) {
                if (count < 2)
                    A[++j] = A[i];
                count++;
            } else {
                A[++j] = A[i];
                count = 1;
            }
        }

        return j + 1;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 1, 1, 2, 2, 3};
        int n = so.removeDuplicates(A);
        printvector(A, 0, n);
    }
    {
        A = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        int n = so.removeDuplicates(A);
        printvector(A, 0, n);
    }
    {
        A = {1, 2};
        int n = so.removeDuplicates(A);
        printvector(A, 0, n);
    }
    {
        A = {1};
        int n = so.removeDuplicates(A);
        printvector(A, 0, n);
    }
    {
        A = {};
        int n = so.removeDuplicates(A);
        printvector(A, 0, n);
    }
    return 0;
}