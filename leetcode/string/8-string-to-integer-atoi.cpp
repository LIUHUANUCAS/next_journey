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
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            return 0;
        int sign = 0;
        if (s[i] == '-' || s[i] == '+') {
            sign = s[i] == '-';
            i++;
        }
        int sum = 0;
        for (int j = i; j < n && isdigit(s[j]); ++j) {
            int num = s[j] - '0';
            if (sum > INT_MAX / 10 ||
                (sum == INT_MAX / 10 && num > INT_MAX % 10)) {
                return sign ? INT_MIN : INT_MAX;
            }
            sum *= 10;
            sum += num;
        }
        if (sign)
            return -sum;
        return sum;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "42";
        cout << "input: " << s << endl;
        cout << "output: " << so.myAtoi(s) << endl;
    }
    {
        s = "   -42";
        cout << "input: " << s << endl;
        cout << "output: " << so.myAtoi(s) << endl;
    }
    {
        s = "4193 with words";
        cout << "input: " << s << endl;
        cout << "output: " << so.myAtoi(s) << endl;
    }
    {
        s = "-91283472332";
        cout << "input: " << s << endl;
        cout << "output: " << so.myAtoi(s) << endl;
    }
    return 0;
}