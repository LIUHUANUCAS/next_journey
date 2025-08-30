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
    int candy(vector<int>& A) {
        int n = A.size();
        vector<int> left(n, 0), right(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && A[i] > A[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        int ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && A[i] > A[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            ret += max(left[i], right[i]);
        }
        return ret;
    }
};
int main() {
    Solution so;
    vector<int> ratings;
    {
        ratings = {1, 0, 2};
        auto r = so.candy(ratings);
        cout << "result:" << r << endl;
    }
    {
        ratings = {1, 2, 2};
        auto r = so.candy(ratings);
        cout << "result:" << r << endl;
    }
    {
        ratings = {1, 3, 4, 5, 2};
        auto r = so.candy(ratings);
        cout << "result:" << r << endl;
    }
    {
        ratings = {1, 2, 87, 87, 87, 2, 1};
        auto r = so.candy(ratings);
        cout << "result:" << r << endl;
    }
    return 0;
}