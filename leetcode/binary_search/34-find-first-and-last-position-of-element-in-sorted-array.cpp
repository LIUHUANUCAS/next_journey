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
    vector<int> searchRange(vector<int>& A, int target) {
        int n = A.size();
        int left = lower_bound(A, target);
        int right = upper_bound(A, target);
        if (left == n || A[left] != target)
            return {-1, -1};
        return {left, right - 1};
    }

    int upper_bound(vector<int>& A, int target) {
        int n = A.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int x = A[mid];
            if (x == target) {
                left = mid + 1;
            } else if (x < target) {
                left = mid + 1;
            } else if (x > target) {
                right = mid;
            }
        }
        return right;
    }

    int lower_bound(vector<int>& A, int target) {
        int n = A.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int x = A[mid];
            if (target == x) {
                right = mid;
            } else if (target < x) {
                right = mid;
            } else if (target > x) {
                left = mid + 1;
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
        A = {5, 7, 7, 8, 8, 10};
        target = 2;
        auto r = so.searchRange(A, target);
        printvector(r);
    }
    {
        A = {5, 7, 7, 8, 8, 10, 12};
        target = 11;
        auto r = so.searchRange(A, target);
        printvector(r);
    }

    return 0;
}