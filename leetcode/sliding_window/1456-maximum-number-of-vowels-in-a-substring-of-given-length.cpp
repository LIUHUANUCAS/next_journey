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
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, max_len = 0, vowels = 0;

        while (j < n) {
            char c = s[j];
            j++;
            while (j - i > k) {
                if (is_vowels(s[i]))
                    --vowels;
                i++;
            }
            if (is_vowels(c)) {
                ++vowels;
            }

            if (j - i == k) {
                max_len = max(max_len, vowels);
            }
        }
        return max_len;
    }
    bool is_vowels(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main() {
    Solution so;
    string s;
    {
        s = "abciiidef";
        int k = 3;
        auto res = so.maxVowels(s, k);
        cout << res << endl;  // Output: 3
    }
    {
        s = "aeiou";
        int k = 2;
        auto res = so.maxVowels(s, k);
        cout << res << endl;  // Output: 2
    }
    {
        s = "leetcode";
        int k = 3;
        auto res = so.maxVowels(s, k);
        cout << res << endl;  // Output: 2
    }
    {
        s = "rhythms";
        int k = 4;
        auto res = so.maxVowels(s, k);
        cout << res << endl;  // Output: 0
    }
    return 0;
}