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
    int majorityElement(vector<int>& A) {
        int n = A.size();
        return majority_element_count(A, 0, n - 1);
    }
    int majorityElement2(vector<int>& A) {
        int n = A.size();
        int c = 1, t = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] == t)
                c++;
            else {
                --c;
                if (c == 0) {
                    t = A[i];
                    c = 1;
                }
            }
        }
        return t;
    }
    int majority_element_count(vector<int>& A, int lo, int hi) {
        if (lo == hi)
            return A[lo];
        int mid = (lo + hi) / 2;
        int left = majority_element_count(A, lo, mid);
        int right = majority_element_count(A, mid + 1, hi);
        if (left == right)
            return left;
        int left_count = count_in_range(A, left, lo, hi);
        int right_count = count_in_range(A, right, lo, hi);
        return left_count > right_count ? left : right;
    }
    int count_in_range(vector<int>& A, int val, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; ++i) {
            if (A[i] == val)
                count++;
        }
        return count;
    }
};
int main() {
    Solution so;
    vector<int> A;

    {
        A = {2, 2, 1, 1, 1, 2, 2};
        cout << "majority element:" << so.majorityElement(A) << endl;
        cout << "majority element2:" << so.majorityElement2(A) << endl;
    }
    {
        A = {3, 3, 4};
        cout << "majority element:" << so.majorityElement(A) << endl;
        cout << "majority element2:" << so.majorityElement2(A) << endl;
    }
    {
        A = {1, 2, 3, 4, 5};
        cout << "majority element:" << so.majorityElement(A) << endl;
        cout << "majority element2:" << so.majorityElement2(A) << endl;
    }
    return 0;
}