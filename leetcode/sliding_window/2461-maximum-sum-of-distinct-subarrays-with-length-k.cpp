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
    long long maximumSubarraySum(vector<int>& A, int k) {
        int n = A.size();
        int i = 0, j = 0;
        long long max_sum = 0, sum = 0;
        unordered_set<int> set;
        while (j < n) {
            int t = A[j];
            j++;
            while (set.count(t) || set.size() >= k) {
                set.erase(A[i]);
                sum -= A[i];
                i++;
            }
            sum += t;
            set.insert(t);
            if (set.size() == k) {
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
int main() {
    Solution so;
    vector<int> A;
    int k;
    {
        A = {1, 2, 3, 4, 5};
        k = 2;
        auto ret = so.maximumSubarraySum(A, k);
        cout << ret << endl;  // Expected: 9
    }
    {
        A = {4, 4, 4, 4};
        k = 3;
        auto ret = so.maximumSubarraySum(A, k);
        cout << ret << endl;  // Expected: 0
    }
    {
        A = {1, 5, 4, 2, 9, 9, 9};
        k = 3;
        auto ret = so.maximumSubarraySum(A, k);
        cout << ret << endl;  // Expected: 0
    }
    return 0;
}