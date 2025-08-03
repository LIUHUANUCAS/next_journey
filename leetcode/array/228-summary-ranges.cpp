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
    vector<string> summaryRanges(vector<int>& A) {
        int n = A.size();
        vector<string> ret;
        int j = 1, i = 0;
        while (i < n) {
            int t = A[i];
            j = i + 1;
            while (j < n && A[j] == A[j - 1] + 1)
                j++;
            // string temp = to_string(t);
            if (j == i + 1) {
                ret.push_back(to_string(t));
            } else {
                ret.push_back(to_string(t) + "->" + to_string(A[j - 1]));
            }
            i = j;
        }
        return ret;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {0, 1, 2, 4, 5, 7};
        auto r = so.summaryRanges(A);
        printvector(r);
    }
    return 0;
}