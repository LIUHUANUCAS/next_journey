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
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        unordered_map<char, int> count;
        int match_count = 0;
        for (auto c : p) {
            if (count[c] == 0) {
                match_count++;
            }
            count[c]++;
        }
        int i = 0, j = 0;
        vector<int> res;

        while (j < n) {
            char c = s[j];
            count[c]--;
            if (count[c] == 0) {
                match_count--;
            }

            if (match_count == 0) {
                res.push_back(i);
            }

            j++;
            if (j >= m) {  // window size is m, we need to move i
                char c = s[i];
                if (count[c] == 0) {
                    match_count++;
                }
                count[c]++;
                i++;
            }
        }
        return res;
    }
};
int main() {
    Solution so;

    return 0;
}