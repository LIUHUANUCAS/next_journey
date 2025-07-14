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
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, count = 0;
        unordered_set<char> set;
        while (j < n) {
            char c = s[j];
            j++;
            while (set.count(c)) {
                set.erase(s[i]);
                i++;
            }

            set.insert(c);
            while (set.size() > k) {
                set.erase(s[i]);
                i++;
            }
            if (set.size() == k) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution so;
    string s;
    {
        s = "havefunonleetcode";
        int k = 5;
        auto res = so.numKLenSubstrNoRepeats(s, k);
        cout << res << endl;  // Output: 6
    }
    {
        s = "home";
        int k = 5;
        auto res = so.numKLenSubstrNoRepeats(s, k);
        cout << res << endl;  // Output: 0
    }
    return 0;
}