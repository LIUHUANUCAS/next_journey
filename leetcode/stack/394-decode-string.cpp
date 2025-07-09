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
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        for (auto c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                while (!numstack.empty() && isdigit(s.back)) {
                }
            }
        }
    }
};

int main() {
    Solution so;
    string s;
    {
        s = "3[a]2[bc]";
        cout << so.decodeString(s) << endl;  // Output: "aaabcbc"
    }
    {
        s = "3[a2[c]]";
        cout << so.decodeString(s) << endl;  // Output: "accaccacc"
    }
    {
        s = "2[abc]3[cd]ef";
        cout << so.decodeString(s) << endl;  // Output: "abcabccdcdcdef"
    }
    {
        s = "abc3[cd]xyz";
        cout << so.decodeString(s) << endl;  // Output: "abccdcdcdxyz"
    }
    return 0;
}