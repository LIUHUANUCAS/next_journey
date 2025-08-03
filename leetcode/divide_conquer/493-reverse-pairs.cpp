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
    vector<int> temp;

   public:
    int reversePairs(vector<int>& A) {
        int n = A.size();
        temp.resize(n);
        return divide_conquer(A, 0, n - 1);
    }
    int divide_conquer(vector<int>& A, int low, int high) {
        if (low >= high)
            return 0;
        int mid = (low + high) >> 1;
        int left = divide_conquer(A, low, mid);
        int right = divide_conquer(A, mid + 1, high);
        int mid_across_value = reverse_pair_across_mid(A, low, mid, high);
        return left + right + mid_across_value;
    }
    int reverse_pair_across_mid(vector<int>& A, int low, int mid, int high) {
        int count = 0;
        for (int i = low, j = mid + 1; i <= mid; ++i) {
            while (j <= high && (long long)A[i] > 2 * (long long)A[j])
                ++j;
            count += j - (mid + 1);
        }
        // merge [low,mid], [mid+1,high];
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high) {
            if (A[i] <= A[j])
                temp[k++] = A[i++];
            else
                temp[k++] = A[j++];
        }
        while (i <= mid)
            temp[k++] = A[i++];
        while (j <= high)
            temp[k++] = A[j++];
        for (int i = low; i <= high; ++i) {
            A[i] = temp[i];
        }
        return count;
    }
};

int main() {
    Solution so;

    return 0;
}