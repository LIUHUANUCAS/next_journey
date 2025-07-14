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
    int lengthOfLastWord(string s) {
        int len = 0, j = s.size() - 1;
        while (j >= 0 && s[j] == ' ')
            --j;
        len = 0;
        while (j >= 0 && s[j] != ' ') {
            ++len;
            --j;
        }

        return len;
    }
};
int main() {
    Solution so;
    string s;
    {
        s = "Hello World";
        cout << so.lengthOfLastWord(s) << endl;  // Output: 5
    }
    {
        s = "   fly me   to   the moon  ";
        cout << so.lengthOfLastWord(s) << endl;  // Output: 4
    }
    {
        s = "luffy is still joyboy";
        cout << so.lengthOfLastWord(s) << endl;  // Output: 6
    }
    return 0;
}