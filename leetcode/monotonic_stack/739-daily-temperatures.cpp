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
    vector<int> dailyTemperatures(vector<int>& A) {
        int size = A.size();
        vector<int> ret(size, 0);
        stack<int> st;
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && A[st.top()] < A[i]) {
                auto j = st.top();
                // printf("i: %d, j: %d, A[i]: %d, A[j]: %d\n", i, j, A[i], A[j]);
                st.pop();
                ret[j] = i - j;
            }
            st.push(i);
        }
        return ret;
    }
};

int main() {
    Solution so;
    vector<int> A;
    {
        A = {73, 74, 75, 71, 69, 72, 76, 73};

        auto r = so.dailyTemperatures(A);
        printvector(r);
    }
    {
        A = {30, 40, 50, 60};

        auto r = so.dailyTemperatures(A);
        printvector(r);
    }

    {
        A = {30, 60, 90};

        auto r = so.dailyTemperatures(A);
        printvector(r);
    }

    return 0;
}