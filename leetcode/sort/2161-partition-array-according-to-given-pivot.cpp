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
    vector<int> pivotArray(vector<int>& A, int pivot) {
        int n = A.size();
        vector<int> ret(n, pivot);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (A[i] < pivot) {
                ret[left] = A[i];
                ++left;
            } else if (A[i] > pivot) {
                ret[right] = A[i];
                --right;
            }
        }
        reverse(ret.begin() + right + 1, ret.end());
        return ret;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {9, 12, 5, 10, 14, 3, 10};
        int pivot = 10;
        auto ret = so.pivotArray(A, pivot);
        printvector(ret);  // Expected: [9, 5, 3, 10, 10, 12, 14]
    }
    {
        A = {-3, -2, -4, -1};
        int pivot = -2;
        auto ret = so.pivotArray(A, pivot);
        printvector(ret);  // Expected: [-3, -4, -2, -1]
    }
    return 0;
}