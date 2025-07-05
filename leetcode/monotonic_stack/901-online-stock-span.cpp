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

class StockSpanner {
    stack<pair<int, int>> st;

   public:
    StockSpanner() {}

    int next(int price) {
        int r = 1;
        while (!st.empty() && st.top().first <= price) {
            r += st.top().second;
            st.pop();
        }
        st.push({price, r});
        return r;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    // Solution so;
    vector<int> A;
    {
        StockSpanner* obj = new StockSpanner();
        A = {100, 80, 60, 70, 60, 75, 85};
        for (auto price : A) {
            auto out = obj->next(price);
            // cout << out << ",";
            printf("price:%d,%d\n", price, out);
        }
        cout << endl;
    }
    return 0;
}