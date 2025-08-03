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
    int minMutation(string s, string t, vector<string>& bank) {
        int n = s.size();

        vector<int> visited(bank.size(), 0);

        queue<string> que;
        que.push(s);
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            step++;
            for (int k = 0; k < size; ++k) {
                auto x = que.front();
                que.pop();
                for (int i = 0; i < bank.size(); ++i) {
                    int c = 0;
                    for (int j = 0; j < n && c < 2; ++j) {
                        if (bank[i][j] != x[j])
                            c++;
                    }
                    if (c == 1 && !visited[i]) {
                        if (bank[i] == t)
                            return step;
                        que.push(bank[i]);
                        visited[i] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
int main() {
    Solution so;
    string s, t;
    vector<string> bank;
    {
        s = "AACCGGTT";
        t = "AACCGGTA";
        bank = {"AACCGGTA"};
        cout << so.minMutation(s, t, bank) << endl;  // 1
    }
    {
        s = "AACCGGTT";
        t = "AAACGGTA";
        bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        cout << so.minMutation(s, t, bank) << endl;  // 2
    }
    {
        s = "AAAAACCC";
        t = "AACCCCCC";
        bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        cout << so.minMutation(s, t, bank) << endl;  // 3
    }
    {
        s = "AACCGGTT";
        t = "AACCGGTA";
        bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        cout << so.minMutation(s, t, bank) << endl;  // 1
    }
    {
        s = "AAAAACCC";
        t = "AACCCCCC";
        bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        cout << so.minMutation(s, t, bank) << endl;  // 3
    }
    return 0;
}