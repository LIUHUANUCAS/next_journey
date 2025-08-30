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
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int m = A.size(), n = A[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (A[i][j] == target)
                return true;
            if (A[i][j] > target)
                j--;
            else if (A[i][j] < target)
                i++;
        }
        return false;
    }
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target)
                return true;
        }
        return false;
    }
};
int main() {
    Solution so;
    vector<vector<int>> A;
    int target;
    {
        A = {
            {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}, {60, 61, 62, 63}};
        target = 3;
        auto r = so.searchMatrix(A, target);
        cout << "result:" << r << endl;
    }
    {
        A = {{1}};
        target = 2;
        auto r = so.searchMatrix(A, target);
        cout << "result:" << r << endl;
    }
    {
        A = {{1}};
        target = 1;
        auto r = so.searchMatrix(A, target);
        cout << "result:" << r << endl;
    }
    return 0;
}