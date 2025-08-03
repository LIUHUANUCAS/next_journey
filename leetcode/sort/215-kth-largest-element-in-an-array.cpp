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
    int findKthLargest(vector<int>& A, int k) {
        int n = A.size();
        auto first = A.begin(), last = A.end();
        int pivot = 0;
        int kth = n - k;
        while (true) {
            pivot = *first;
            auto p = partition(first, last, pivot);
            int loc = p - A.begin();
            printvector(A);
            printf("loc:%d, kth:%d, pivot:%d\n", loc, kth, pivot);
            if (loc == kth)
                return *p;
            else if (kth > loc) {
                first = ++p;
            } else if (kth < loc) {
                last = p;
            }
        }
        return *first;
    }
    template <class RandomAccessIterator, class T>
    RandomAccessIterator partition(RandomAccessIterator first,
                                   RandomAccessIterator last,
                                   T pivot) {
        while (true) {
            while (*first < pivot)
                ++first;
            --last;
            while (pivot < *last)
                --last;
            if (!(first < last)) {
                // printf("first:%d, last:%d\n", *first, *last);

                return first;
            }
            iter_swap(first, last);
            ++first;
        }
        return first;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    {
        A = {3, 2, 1, 5, 6, 4};
        k = 2;
        cout << so.findKthLargest(A, k) << endl;  // 5
    }
    return 0;
}