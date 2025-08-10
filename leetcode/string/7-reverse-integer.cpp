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
    int reverse(int x) {
        int sign = x < 0;
        string s(to_string(x));
        int i = 0, n = s.size();
        if (s[i] == '-') {
            i++;
        }
        int sum = 0, num = 0;
        for (int j = n - 1; j >= i; --j) {
            num = s[j] - '0';
            if (sum > INT_MAX / 10 ||
                sum == INT_MAX / 10 && num > INT_MAX % 10) {
                return 0;
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
    int x;
    {
        x = 123;
        cout << "input: " << x << endl;
        cout << "output: " << so.reverse(x) << endl;
    }
    {
        x = -123;
        cout << "input: " << x << endl;
        cout << "output: " << so.reverse(x) << endl;
    }
    {
        x = 120;
        cout << "input: " << x << endl;
        cout << "output: " << so.reverse(x) << endl;
    }
    {
        x = 1534236469;  // overflow
        cout << "input: " << x << endl;
        cout << "output: " << so.reverse(x) << endl;
    }
    return 0;
}