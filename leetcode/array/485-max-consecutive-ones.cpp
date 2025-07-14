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
    int findMaxConsecutiveOnes(vector<int>& A) {
        int n = A.size(), count = 0, max_len = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) {
                ++count;
            } else {
                max_len = max(max_len, count);
                count = 0;
            }
        }
        max_len = max(max_len, count);
        return max_len;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 1, 0, 1, 1, 1};
        auto res = so.findMaxConsecutiveOnes(A);
        cout << res << endl;  // Output: 3
    }
    {
        A = {1, 0, 1, 1, 0, 1};
        auto res = so.findMaxConsecutiveOnes(A);
        cout << res << endl;  // Output: 2
    }
    return 0;
}