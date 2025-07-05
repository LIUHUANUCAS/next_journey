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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices);
        stack<int> st;
        for (int i = 0; i < prices.size(); ++i) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int j = st.top();
                st.pop();
                res[j] = prices[j] - prices[i];
            }
            st.push(i);
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {8, 4, 6, 2, 3};
        auto r = so.finalPrices(A);
        printvector(r);
    }
    {
        A = {1, 2, 3, 4, 5};
        auto r = so.finalPrices(A);
        printvector(r);
    }

    {
        A = {10, 1, 1, 6};
        auto r = so.finalPrices(A);
        printvector(r);
    }
    return 0;
}