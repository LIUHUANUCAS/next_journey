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
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        int left = 0, right = 0;
        function<void(int)> backtrack = [&](int i) {
            if (i == 2 * n) {
                ret.push_back(path);
                return;
            }

            // two options
            // 1. push (, left++;
            if (left >= right && left < n) {
                path.push_back('(');
                left++;
                backtrack(i + 1);
                path.pop_back();
                left--;
            }
            // 2. push ) right++;
            if (left > right && right < n) {
                path.push_back(')');
                right++;
                backtrack(i + 1);
                right--;
                path.pop_back();
            }
        };
        backtrack(0);
        return ret;
    }
};
int main() {
    Solution so;
    int n = 5;
    for (int i = 1; i <= n; ++i) {
        auto ret = so.generateParenthesis(i);
        printvector(ret);
    }
    return 0;
}