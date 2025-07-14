#include <cstdio>
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
    vector<int> aux;

   public:
    vector<int> sortArray(vector<int>& A) {
        int n = A.size();
        aux.resize(n);
        merge(A, 0, n - 1);
        return A;
    }
    void merge(vector<int>& A, int lo, int hi) {
        if (lo == hi)
            return;
        int mid = lo + (hi - lo) / 2;
        merge(A, lo, mid);
        merge(A, mid + 1, hi);
        mergeArray(A, lo, mid, hi);
    }
    void mergeArray(vector<int>& A, int lo, int mid, int hi) {
        for (int k = lo; k <= hi; ++k) {
            aux[k] = A[k];
        }
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            if (i > mid) {  // first part is finished
                A[k] = aux[j++];
            } else if (j > hi) {  // second part is finished
                A[k] = aux[i++];
            } else if (aux[i] < aux[j]) {  // both are in passing
                A[k] = aux[i++];
            } else {
                A[k] = aux[j++];
            }
        }
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {5, 2, 3, 1};
        auto res = so.sortArray(A);
        printvector(res);
    }
    {
        A = {5, 1, 1, 2, 0, 0};
        auto res = so.sortArray(A);
        printvector(res);
    }
    {
        A = {1, 2, 3, 4, 5};
        auto res = so.sortArray(A);
        printvector(res);
    }
    {
        A = {5, 4, 3, 2, 1};
        auto res = so.sortArray(A);
        printvector(res);
    }
    return 0;
}