#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../../data_type.h"

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<int> ret(n, -1);
        unordered_map<int, int> umap;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            umap[B[i]] = i;
            while (!st.empty() && B[st.top()] < B[i]) {
                auto j = st.top();
                st.pop();
                ret[j] = i;
            }
            st.push(i);
        }
        vector<int> res(m, -1);
        for (int i = 0; i < m; ++i) {
            auto idx = umap[A[i]];
            if (ret[idx] > 0) {
                res[i] = B[ret[idx]];
            }
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<int> A, B;
    {
        A = {4, 1, 2}, B = {1, 3, 4, 2};
        auto r = so.nextGreaterElement(A, B);
        printvector(r);
    }
    {
        A = {2, 4}, B = {1, 2, 3, 4};
        auto r = so.nextGreaterElement(A, B);
        printvector(r);
    }
    return 0;
}