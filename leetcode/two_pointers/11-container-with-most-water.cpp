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
    int maxArea(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1, ret = 0;
        while (i < j) {
            ret = max(get_area(A, i, j), ret);
            if (A[i] < A[j])
                i++;
            else
                j--;
        }
        return ret;
    }
    int get_area(vector<int>& A, int i, int j) {
        return min(A[i], A[j]) * (j - i);
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        cout << so.maxArea(A) << endl;  // 49
    }
    {
        A = {1, 1};
        cout << so.maxArea(A) << endl;  // 1
    }
    {
        A = {4, 3, 2, 1, 4};
        cout << so.maxArea(A) << endl;  // 16
    }
    {
        A = {1, 2, 1};
        cout << so.maxArea(A) << endl;  // 2
    }
    {
        A = {2, 3, 10, 5, 7, 8};
        cout << so.maxArea(A) << endl;  // 36
    }
    return 0;
}