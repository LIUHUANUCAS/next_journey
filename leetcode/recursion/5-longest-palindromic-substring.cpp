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
    unordered_map<int, unordered_map<int, bool>> memo;
    int len = 1;
    int idx = 0;

   public:
    string longestPalindrome(string s) {
        memo.clear();
        len = 1, idx = 0;
        int n = s.size();
        dfs(s, 0, n - 1);
        return string(s.begin() + idx, s.begin() + idx + len);
    }

    bool dfs(string& s, int i, int j) {
        if (i > j)
            return false;
        int res = s[i] == s[j];
        if (i == j) {
            memo[i][j] = res;
            return memo[i][j];
        }
        if (i == j - 1) {
            memo[i][j] = res;
            if (memo[i][j] && len < j - i + 1) {
                len = j - i + 1;
                idx = i;
            }
            return memo[i][j];
        }

        if (memo.count(i) && memo[i].count(j))
            return memo[i][j];
        int r = dfs(s, i + 1, j - 1);
        if (r && res && len < j - i + 1) {
            len = j - i + 1;
            idx = i;
        }

        if (dfs(s, i + 1, j) && len < j - i) {
            len = j - i;
            idx = i + 1;
        }

        if (dfs(s, i, j - 1) && len < j - i) {
            len = j - i;
            idx = i;
        }
        return memo[i][j] = r && res;
    }
};
int main() {
    Solution so;
    string s;
    // {
    //     s = "babaddbdd";
    //     cout << so.longestPalindrome(s) << endl;  // Output: "bab" or "aba"
    // }
    {
        s = "ajgiljtperkvubjmdsefcylksrxtftqrehoitdgdtttswwttmfuvwgwrruuqmxttzs"
            "bmuhgfaoueumvbhajqsaxkkihjwevzzedizmrsmpxqavyryklbotwzngxscvyuqjkk"
            "aotitddlhhnutmotupwuwyltebtsdfssbwayuxrbgihmtphshdslktvsjadaykyjiv"
            "bzhwujcdvzdxxfiixnzrmusqvwujjmxhbqbdpauacnzojnzxxgrkmupadfcsujkcwa"
            "jsgintahwgbjnvjqubcxajdyyapposrkpqtpqfjcvbhlmwfutgognqxgaukpmdyaxg"
            "hgoqkqnigcllachmwzrazwhpppmsodvxilrccfqgpkmdqhoorxpyjsrtbeeidsinpe"
            "yxxpsjnymxkouskyhenzgieybwkgzrhhrzgkwbyeigznehyksuokxmynjspxxyepni"
            "sdieebtrsjypxroohqdmkpgqfccrlixvdosmppphwzarzwmhcallcginqkqoghgxay"
            "dmpkuagxqngogtufwmlhbvcjfqptqpkrsoppayydjaxcbuqjvnjbgwhatnigsjawck"
            "juscfdapumkrgxxznjozncauapdbqbhxmjjuwvqsumrznxiifxxdzvdcjuwhzbvijy"
            "kyadajsvtklsdhshptmhigbrxuyawbssfdstbetlywuwputomtunhhlddtitoakkjq"
            "uyvcsxgnzwtoblkyryvaqxpmsrmzidezzvewjhikkxasqjahbvmueuoafghumbsztt"
            "xmquurrwgwvufmttwwstttdgdtioherqtftxrsklycfesdmjbuvkreptjligja";
        cout << so.longestPalindrome(s) << endl;  // Output: "bb"
    }
    // {
    //     s = "a";
    //     cout << so.longestPalindrome(s) << endl;  // Output: "a"
    // }
    // {
    //     s = "ac";
    //     cout << so.longestPalindrome(s) << endl;  // Output: "a" or "c"
    // }
    return 0;
}