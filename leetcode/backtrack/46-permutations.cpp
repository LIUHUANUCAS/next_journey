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
    vector<int> visited;
    vector<vector<int>> ret;

   public:
    vector<vector<int>> permute(vector<int>& A) {
        int n = A.size();
        visited.resize(n);
        ret.clear();
        vector<int> path;
        dfs(A, path);
        return ret;
    }
    void dfs(vector<int>& A, vector<int>& path) {
        if (path.size() == A.size()) {
            ret.push_back(path);
            return;
        }
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = 1;
                path.push_back(A[i]);
                dfs(A, path);
                path.pop_back();
                visited[i] = 0;
            }
        }
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 3};
        auto ret = so.permute(A);
        printvector(ret);  // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    }
    {
        A = {0, 1};
        auto ret = so.permute(A);
        printvector(ret);  // [[0,1],[1,0]]
    }
    {
        A = {1};
        auto ret = so.permute(A);
        printvector(ret);  // [[1]]
    }
    return 0;
}