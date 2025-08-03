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
    vector<vector<int>> insert(vector<vector<int>>& A,
                               vector<int>& newInterval) {
        int n = A.size();
        auto lower = lower_bound(A.begin(), A.end(), newInterval);
        vector<vector<int>> ret(A.begin(), lower);

        if (lower == A.end()) {
            merge(ret, newInterval);
            return ret;
        }

        merge(ret, newInterval);
        for (auto it = lower; it != A.end(); ++it) {
            merge(ret, *it);
        }
        return ret;
    }
    void merge(vector<vector<int>>& ret, vector<int>& newInterval) {
        if (ret.empty()) {
            ret.push_back(newInterval);
            return;
        }
        if (ret.back()[1] < newInterval[0]) {
            ret.push_back(newInterval);
        } else {
            ret.back()[1] = max(ret.back()[1], newInterval[1]);
        }
    }
};
int main() {
    Solution so;

    return 0;
}