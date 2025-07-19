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
    int maxProduct(vector<int>& A) {
        int n = A.size();
        vector<int> dp_pos(n, 0), dp_neg(n, 0);
        if (A[0] > 0)
            dp_pos[0] = A[0];
        else
            dp_neg[0] = A[0];
        int max_value = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] > 0) {
                dp_pos[i] = max(dp_pos[i - 1] * A[i], A[i]);  // > 0
                dp_neg[i] = dp_neg[i - 1] * A[i];             // < 0
            } else if (A[i] < 0) {
                dp_neg[i] = min(dp_pos[i - 1] * A[i], A[i]);  // < 0
                dp_pos[i] = dp_neg[i - 1] * A[i];             //>0
            }
            max_value = max(dp_pos[i], max_value);
        }
        return max_value;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 3, -2, 4};
        auto r = so.maxProduct(A);
        cout << r << endl;  // 6
    }
    {
        A = {-2, 0, -1};
        auto r = so.maxProduct(A);
        cout << r << endl;  // 0
    }
    {
        A = {-2, 3, -4};
        auto r = so.maxProduct(A);
        cout << r << endl;  // 24
    }
    {
        A = {-1, -2, -9, -6};
        auto r = so.maxProduct(A);
        cout << r << endl;  // 108
    }
    return 0;
}