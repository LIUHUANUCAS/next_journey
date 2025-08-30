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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        backtrack(ret, candidates, path, 0, target);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret,
                   vector<int>& A,
                   vector<int>& path,
                   int idx,
                   int target) {
        if (target < 0 || idx >= A.size())
            return;
        if (target == 0) {
            ret.push_back(path);
            return;
        }
        backtrack(ret, A, path, idx + 1, target);
        if (target - A[idx] >= 0) {
            path.push_back(A[idx]);
            backtrack(ret, A, path, idx, target - A[idx]);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    vector<int> candidates;
    int target;
    {
        candidates = {2, 3, 6, 7};
        target = 7;
        auto r = so.combinationSum(candidates, target);
        cout << "candidates={2,3,6,7}, target=7" << endl;
        printvector(r);
    }
    {
        candidates = {2, 3, 5};
        target = 8;
        auto r = so.combinationSum(candidates, target);
        cout << "candidates={2,3,5}, target=8" << endl;
        printvector(r);
    }
    {
        candidates = {2};
        target = 1;
        auto r = so.combinationSum(candidates, target);
        cout << "candidates={2}, target=1" << endl;
        printvector(r);
    }
    return 0;
}