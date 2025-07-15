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
    int minSubArrayLen(int target, vector<int>& A) {
        int n = A.size();
        int i = 0, j = 0, min_len = n + 1;
        int sum = 0;
        while (j < n) {
            int t = A[j++];
            sum += t;

            while (sum >= target) {
                min_len = min(min_len, j - i);
                sum -= A[i];
                i++;
            }
        }
        return min_len == n + 1 ? 0 : min_len;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 3, 1, 2, 4, 3};
        int target = 7;
        cout << so.minSubArrayLen(target, A) << endl;  // 2
    }
    {
        A = {1, 4, 4};
        int target = 4;
        cout << so.minSubArrayLen(target, A) << endl;  // 1
    }
    {
        A = {1, 1, 1, 1, 1, 1};
        int target = 11;
        cout << so.minSubArrayLen(target, A) << endl;  // 0
    }
    return 0;
}