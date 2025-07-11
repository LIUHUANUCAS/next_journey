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
    int removeElement(vector<int>& A, int val) {
        int n = A.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != val) {
                A[j++] = A[i];
            }
        }
        return j;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int val;
    {
        A = {3, 2, 2, 3};
        val = 3;
        int res = so.removeElement(A, val);
        cout << res << endl;  // Output: 2
        printvector(A);
    }
    {
        A = {0, 1, 2, 2, 3, 0, 4, 2};
        val = 2;
        int res = so.removeElement(A, val);
        cout << res << endl;  // Output: 5
        printvector(A);
    }
    return 0;
}