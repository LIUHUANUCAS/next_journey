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
    void rotate(vector<int>& A, int k) {
        int n = A.size();
        if (n == 0 || k <= 0 || k % n == 0)
            return;
        k = k % n;
        reverse(A.begin(), A.end());
        reverse(A.begin(), A.begin() + k);
        reverse(A.begin() + k, A.end());
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 3, 4, 5, 6, 7};
        so.rotate(A, 3);
        printvector(A);  // 5 6 7 1 2 3 4
    }
    return 0;
}