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
    vector<int> nextGreaterElements(vector<int>& A) {
        int size = A.size();
        vector<int> ret(size, -1);
        stack<int> st;
        for (int i = 0; i < size * 2; ++i) {
            int idx = i % size;
            while (!st.empty() && A[st.top()] < A[idx]) {
                auto j = st.top();
                st.pop();
                ret[j] = A[idx];
            }
            if (i < size) {
                st.push(idx);
            }
        }
        return ret;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 1};

        auto r = so.nextGreaterElements(A);
        printvector(r);
    }
    {
        A = {1, 2, 3, 4, 3};

        auto r = so.nextGreaterElements(A);
        printvector(r);
    }
    return 0;
}