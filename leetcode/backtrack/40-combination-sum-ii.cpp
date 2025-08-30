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
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        vector<int> path;
        vector<vector<int>> ret;
        vector<int> selected(A.size(), 0);
        function<void(int, int)> backtrack = [&](int idx, int target) {
            if (target == 0) {
                ret.push_back(path);
                return;
            }
            if (idx >= A.size())
                return;

            backtrack(idx + 1, target);
            if (idx > 0 && A[idx] == A[idx - 1] && !selected[idx - 1])
                return;
            if (target - A[idx] >= 0) {
                selected[idx] = 1;
                path.push_back(A[idx]);
                backtrack(idx + 1, target - A[idx]);
                path.pop_back();
                selected[idx] = 0;
            }
        };
        backtrack(0, target);
        return ret;
    }
};
int main() {
    Solution so;

    return 0;
}