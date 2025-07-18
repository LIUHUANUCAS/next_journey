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
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        for (auto c : t) {
            ++tmap[c];
        }
        int tsize = t.size();
        int n = s.size();
        int i = 0, j = 0, min_len = n;

        unordered_map<char, int> umap;

        int covered_count = tmap.size();  // uniq char
        unordered_map<char, int> matches;

        if (covered_count == 0)
            return string(s.begin(), s.begin() + tsize);

        int start_index = -1;
        auto match_t = [&](char t) {
            return !matches[t] && umap[t] >= tmap[t];
        };

        auto not_match_t = [&](char t) {
            return matches[t] && umap[t] < tmap[t];
        };

        while (j < n) {
            auto t = s[j];
            j++;

            if (tmap.count(t)) {
                umap[t]++;
                if (match_t(t)) {
                    covered_count--;
                    matches[t] = 1;
                }
            }

            while (covered_count == 0) {
                if (tmap.count(s[i])) {
                    umap[s[i]]--;
                    if (not_match_t(s[i])) {
                        covered_count++;
                        matches[s[i]] = 0;
                    }
                    if (umap[s[i]] == 0) {
                        umap.erase(s[i]);
                    }
                }

                if (j - i <= min_len) {
                    start_index = i;
                    min_len = j - i;
                }

                i++;
            }
        }
        if (start_index < 0)
            return "";
        return string(s.begin() + start_index,
                      s.begin() + start_index + min_len);
    }
    string minWindow2(string s, string t) {
        int n = s.size();
        int i = 0, j = 0, min_len = n, match_count = 0;
        int start_index = -1;

        int count[128]{};

        for (auto c : t) {
            if (count[c] == 0) {
                ++match_count;
            }
            count[c]++;
        }

        while (j < n) {
            auto c = s[j];
            count[c]--;

            if (count[c] == 0) {
                match_count--;
            }
            j++;

            while (match_count == 0) {
                if (j - i <= min_len) {
                    start_index = i;
                    min_len = j - i;
                }
                char x = s[i];
                if (count[x] == 0) {
                    match_count++;
                }
                count[x]++;
                i++;
            }
        }
        if (start_index < 0)
            return "";
        return string(s.begin() + start_index,
                      s.begin() + start_index + min_len);
    }
};

int main() {
    Solution so;
    string s, t;
    {
        s = "ADOBECODEBANC";
        t = "ABC";
        cout << so.minWindow(s, t) << endl;  // "BANC"
    }
    {
        s = "a";
        t = "a";
        cout << so.minWindow(s, t) << endl;  // "a"
    }
    {
        s = "a";
        t = "aa";
        cout << so.minWindow(s, t) << endl;  // ""
    }
    {
        s = "cabwefgewcwaefgcf";
        t = "cae";
        cout << so.minWindow(s, t) << endl;  // "cwae"
    }
    return 0;
}