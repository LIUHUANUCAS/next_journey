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
    void sortColors(vector<int>& A) {
        int n = A.size();
        if (n <= 1)
            return;
        int p0 = 0, p1 = 0, p2 = n - 1;
        while (p1 <= p2) {
            if (A[p1] == 0) {
                swap(A[p0], A[p1]);
                p0++;
                p1++;
            } else if (A[p1] == 1) {
                p1++;
            } else {
                swap(A[p1], A[p2]);
                p2--;
            }
        }
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 0, 2, 1, 1, 0};
        so.sortColors(A);
        printvector(A);
    }
    {
        A = {2, 0, 1, 1};
        so.sortColors(A);
        printvector(A);
    }

    return 0;
}