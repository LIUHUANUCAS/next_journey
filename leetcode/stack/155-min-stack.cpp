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

class MinStack {
    stack<pair<int, int>> st;

   public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }
        st.push({val, min(val, st.top().second)});
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        st.pop();
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
    // Solution so;
    {
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        auto r = minStack.getMin();
        cout << r << endl;
        // --> 返回 - 3.
        minStack.pop();
        r = minStack.top();
        cout << r << endl;  // --> 返回 0.
        r = minStack.getMin();
        cout << r << endl;
        // --> 返回 - 2.
    }
    return 0;
}