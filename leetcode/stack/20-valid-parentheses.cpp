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
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                if (match(st.top(), c))
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
    bool match(char a, char b) {
        auto c = a - b;
        return c == '(' - ')' || c == '[' - ']' || c == '{' - '}';
    }
};

int main() {
    Solution so;
    string str;
    {
        str = "()";
        auto r = so.isValid(str);
        cout << "str:"<< str << ":" << r << endl;
    }
    {
        str = "()[]{}";
        auto r = so.isValid(str);
        cout << "str:"<< str << ":" << r << endl;
    }
    return 0;
}