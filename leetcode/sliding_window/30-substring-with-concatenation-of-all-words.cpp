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
    vector<int> findSubstring2(string s, vector<string>& words) {
        int size = words[0].size();
        int n = s.size(), m = words.size();

        unordered_map<string, int> umap;
        unordered_map<string, int> matched;
        int match_count = 0;
        for (auto& str : words) {
            if (!umap.count(str)) {
                match_count++;
            }
            umap[str]++;
        }

        int i = 0, j = 0;
        vector<int> ret;
        while (j < n) {
            j += 1;
            // window
            int matched = match_count;
            unordered_map<string, int> tmap(umap.begin(), umap.end());

            // 1. m word in window
            for (int k = i; k < j; k += size) {
                string str(s.substr(k, size));
                tmap[str]--;
                if (tmap[str] == 0) {
                    matched--;
                    tmap.erase(str);
                }
            }
            if (matched == 0) {
                ret.push_back(i);
            }

            // move out window from i with step in size
            for (int k = i; k < n - m * size + 1; k += size) {
                if (k == i)  // already match for 1) m word in window
                    continue;
                // word out of the window,  j+size
                string str(s.substr(k + size * (m - 1), size));
                tmap[str]--;
                if (tmap[str] == 0) {
                    matched--;
                    tmap.erase(str);
                }

                string word(s.substr(k - size, size));
                tmap[word]++;
                if (tmap[word] == 0) {
                    matched++;
                    tmap.erase(word);
                }

                if (matched == 0) {
                    ret.push_back(k);
                }
            }
            if (j >= m * size)
                i++;
        }
        return ret;
    }

    vector<int> findSubstring1(string& s, vector<string>& words) {
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string& word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int size = words[0].size();
        int n = s.size(), m = words.size();

        unordered_map<string, int> umap;
        unordered_map<string, int> matched;
        for (auto& str : words) {
            umap[str]++;
        }

        int match_count = umap.size();
        int i = 0, j = 0;
        vector<int> ret;
        for (int i = 0; i < size && i < n - m * size + 1; ++i) {
            unordered_map<string, int> tmap(umap.begin(), umap.end());
            int matches = umap.size();
            for (int k = 0; k < m; k++) {
                string str(s.substr(i + k * size, size));
                tmap[str]--;
                if (tmap[str] == 0) {
                    tmap.erase(str);
                }
            }

            if (tmap.empty()) {
                ret.push_back(i);
            }

            for (int k = i; k < n - m * size + 1; k += size) {
                if (k == i)
                    continue;
                string str(s.substr(k + (m - 1) * size, size));
                tmap[str]--;
                if (tmap[str] == 0) {
                    tmap.erase(str);
                }
                string word(s.substr(k - size, size));
                tmap[word]++;
                if (tmap[word] == 0) {
                    tmap.erase(word);
                }

                if (tmap.empty()) {
                    ret.push_back(k);
                }
            }
        }
        return ret;
    }
};
int main() {
    Solution so;
    string s;
    vector<string> words;
    {
        s = "barfoothefoobarman";
        words = {"foo", "bar"};
        auto ret = so.findSubstring(s, words);
        printvector(ret);  // 0 9
    }
    // {
    //     s = "wordgoodgoodgoodbestword";
    //     words = {"word", "good", "best", "word"};
    //     auto ret = so.findSubstring(s, words);
    //     printvector(ret);
    // }
    {
        s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

        words = {
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a",
            "a", "a", "a", "a", "a", "a", "a", "a"};
        auto ret = so.findSubstring(s, words);
        printvector(ret);
    }
    return 0;
}