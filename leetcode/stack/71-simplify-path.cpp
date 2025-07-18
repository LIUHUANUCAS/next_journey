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
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();
        int j = 0, i = 0;
        while (j < n) {
            char c = path[j];
            if (c == '/') {  // /{pattern1}/{pattern2}
                string str(1, c);
                i = j + 1;
                while (i < n && path[i] != '/') {
                    str.push_back(path[i]);
                    i++;
                }
                j = i;
                if (str != "/")
                    st.push_back(str);
            }
        }
        vector<string> ret;

        for (auto& s : st) {
            if (s == "/." || s == "/") {
            } else if (s == "/..") {
                if (!ret.empty())
                    ret.pop_back();
            } else {
                ret.push_back(s);
            }
        }

        if (ret.empty())
            return "/";
        string res;
        for (auto& it : ret) {
            res += it;
        }
        return res;
    }
};

int main() {
    Solution so;
    string path;
    {
        path = "/a/./b/../../c/";
        auto res = so.simplifyPath(path);
        cout << res << endl;
    }
    {
        path = "/home/";
        auto res = so.simplifyPath(path);
        cout << res << endl;
    }
    return 0;
}