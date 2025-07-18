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
    int searchInsert(vector<int>& A, int x) { return lower_bound(A, x); }
    int lower_bound(vector<int>& A, int x) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x == A[mid]) {
                return mid;
            } else if (x > A[mid]) {
                left = mid + 1;
            } else if (x < A[mid]) {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution so;
    vector<int> A;
    int target;
    {
        A = {1, 3, 5, 6};
        target = 5;
        auto r = so.searchInsert(A, target);
        cout << r << endl;
    }
    {
        A = {1, 3, 5, 6};
        target = 2;
        auto r = so.searchInsert(A, target);
        cout << r << endl;
    }
    {
        A = {1, 3, 5, 6};
        target = 7;
        auto r = so.searchInsert(A, target);
        cout << r << endl;
    }
    return 0;
}