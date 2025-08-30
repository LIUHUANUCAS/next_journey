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
    void setZeroes(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int row0 = 0, col0 = 0;
        for (int j = 0; j < n; ++j) {
            if (A[0][j] == 0) {
                row0 = 1;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 0) {
                col0 = 1;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (A[i][j] == 0) {
                    A[i][0] = 0;
                    A[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (A[i][0] == 0 || A[0][j] == 0)
                    A[i][j] = 0;
            }
        }

        for (int j = 0; j < n && row0; ++j) {
            A[0][j] = 0;
        }

        for (int i = 0; i < m && col0; ++i) {
            A[i][0] = 0;
        }
    }
};
int main() {
    Solution so;

    return 0;
}