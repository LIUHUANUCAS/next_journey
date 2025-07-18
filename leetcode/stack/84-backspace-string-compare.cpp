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
    bool backspaceCompare(string s, string t) {
        return simplify(s) == simplify(t);
    }
    string simplify(string& s) {
        string str;
        for (auto c : s) {
            if (c == '#') {
                if (!str.empty())
                    str.pop_back();
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
};
int main() {
    Solution so;
    string s, t;
    {
        s = "ab#c";
        t = "ad#c";
        auto r = so.backspaceCompare(s, t);
        cout << r << endl;
    }
    return 0;
}