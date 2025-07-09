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

class NumArray {
    vector<int> prefix_sum;

   public:
    NumArray(vector<int>& A) {
        int n = A.size();
        prefix_sum.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + A[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    // Solution so;
    vector<int> A;
    {
        A = {-2, 0, 3, -5, 2, -1};
        NumArray* obj = new NumArray(A);
        vector<pair<int, int>> data = {{0, 2}, {2, 5}, {0, 5}};
        for (auto e : data) {
            int param_1 = obj->sumRange(e.first, e.second);
            cout << "sumRange(" << e.first << ", " << e.second
                 << ") = " << param_1 << endl;
        }
    }

    return 0;
}