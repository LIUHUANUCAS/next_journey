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
    vector<int> index;
    vector<int> temp_index;
    vector<int> count;

   public:
    vector<int> countSmaller(vector<int>& A) {
        int n = A.size();
        temp.resize(n);
        index.resize(n);
        temp_index.resize(n, 0);
        count.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            index[i] = i;
        }
        divide_conquer(A, 0, n - 1);
        return count;
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
        int reverse_count = 0;
        for (int i = low, j = mid + 1; i <= mid; ++i) {
            while (j <= high && A[i] > A[j])
                ++j;
            int idx = index[i];
            count[idx] += j - (mid + 1);
        }
        merge(A, low, mid, high);
        return reverse_count;
    }

    void merge(vector<int>& A, int low, int mid, int high) {
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high) {
            if (A[i] <= A[j]) {
                temp_index[k] = index[i];
                // count[index[i]] += j - mid - 1;
                temp[k++] = A[i++];
            } else {
                temp_index[k] = index[j];
                temp[k++] = A[j++];
            }
        }
        while (i <= mid) {
            temp_index[k] = index[i];
            // count[index[i]] += j - mid - 1;
            temp[k++] = A[i++];
        }
        while (j <= high) {
            temp_index[k] = index[j];
            temp[k++] = A[j++];
        }
        for (int i = low; i <= high; ++i) {
            A[i] = temp[i];
            index[i] = temp_index[i];
        }
    }
};

int main() {
    Solution so;

    return 0;
}