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
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ret;
        backtrack(ret, path, 1, n, k);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret,
                   vector<int>& path,
                   int start,
                   int end,
                   int k) {
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        for (int i = start; i <= end; ++i) {
            path.push_back(i);
            backtrack(ret, path, i + 1, end, k);
            path.pop_back();
        }
    }
};
int main() {
    Solution so;
    int n;
    int k;
    {
        auto r = so.combine(4, 2);
        cout << "n=4, k=2" << endl;
        printvector(r);
    }
    {
        auto r = so.combine(1, 1);
        cout << "n=1, k=1" << endl;
        printvector(r);
    }
    {
        auto r = so.combine(5, 3);
        cout << "n=5, k=3" << endl;
        printvector(r);
    }
    {
        auto r = so.combine(4, 4);
        cout << "n=4, k=4" << endl;
        printvector(r);
    }
    {
        auto r = so.combine(5, 2);
        cout << "n=5, k=2" << endl;
        printvector(r);
    }
    return 0;
}