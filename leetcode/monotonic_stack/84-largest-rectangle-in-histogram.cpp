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
    int largestRectangleArea(vector<int>& A) { int n = A.size(); }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {2, 1, 5, 6, 2, 3};
        int ans = so.largestRectangleArea(A);
        cout << ans << endl;  // Expected output: 10
    }
    {
        A = {2, 4};
        int ans = so.largestRectangleArea(A);
        cout << ans << endl;  // Expected output: 10
    }

    return 0;
}