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
    int findDuplicate(vector<int>& A) {
        int n = A.size();
        int ret = 0;
        vector<int> temp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (A[i] == temp[A[i]])
                return A[i];
            else {
                temp[A[i]] = A[i];
            }
        }

        return 0;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 3, 4, 2, 2};
        auto r = so.findDuplicate(A);
        cout << r << endl;  // expect 2
    }
    {
        A = {3, 1, 3, 4, 2};
        auto r = so.findDuplicate(A);
        cout << r << endl;  // expect 3
    }
    {
        A = {1, 1};
        auto r = so.findDuplicate(A);
        cout << r << endl;  // expect 1
    }
    return 0;
}