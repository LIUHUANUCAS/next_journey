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
    vector<int> getAverages(vector<int>& A, int k) {
        int n = A.size();
        vector<int> ret(n, -1);
        if (k >= n)
            return ret;
        int i = 0, j = 0, len = 2 * k + 1;
        long int sum = 0L;
        while (j < n) {
            int t = A[j];
            j++;
            sum += t;
            if (j - i < len) {
                continue;
            } else {
                int idx = i + k;
                ret[idx] = sum / len;
                sum -= A[i];
                i++;
            }
        }
        return ret;
    }
};

int main() {
    Solution so;
    vector<int> A;
    int k;
    {
        A = {7, 4, 3, 9, 1, 8, 5, 2, 6};
        k = 3;
        auto ret = so.getAverages(A, k);
        printvector(ret);
    }
    {
        A = {100000};
        k = 0;
        auto ret = so.getAverages(A, k);
        printvector(ret);
    }
    {
        A = {8};
        k = 100000;
        auto ret = so.getAverages(A, k);
        printvector(ret);
    }
    {
        A = {1, 2, 3, 4, 5};
        k = 1;
        auto ret = so.getAverages(A, k);
        printvector(ret);
    }
    return 0;
}