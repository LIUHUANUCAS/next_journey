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
    int trap(vector<int>& A) {
        int n = A.size();
        if (n == 0)
            return 0;
        vector<int> left(n);
        left[0] = A[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], A[i]);
        }

        vector<int> right(n);
        right[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], A[i]);
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += min(left[i], right[i]) - A[i];
        }
        return ret;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        auto r = so.trap(A);
        cout << r << endl;  // expect 6
    }
    {
        A = {4, 2, 0, 3, 2, 5};
        auto r = so.trap(A);
        cout << r << endl;  // expect 9
    }
    {
        A = {0, 1};
        auto r = so.trap(A);
        cout << r << endl;  // expect 0
    }
    {
        A = {1, 0, 2};
        auto r = so.trap(A);
        cout << r << endl;  // expect 1
    }
    {
        A = {2, 0, 2};
        auto r = so.trap(A);
        cout << r << endl;  // expect 2
    }
    {
        A = {3, 2, 1, 2, 1, 5};
        auto r = so.trap(A);
        cout << r << endl;  // expect 8
    }
    return 0;
}