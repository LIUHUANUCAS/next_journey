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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<vector<int>> ret;

   public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ret.clear();
        ret.resize(m, vector<int>(n, -1));
        dfs(ret, 0, 0, m - 1, n - 1, head);
        return ret;
    }

    void dfs(vector<vector<int>>& ret,
             int i,
             int j,
             int l,
             int r,
             ListNode* head) {
        if (i > l || j > r || head == nullptr)
            return;
        if (i == l) {
            for (int col = j; col <= r && head; ++col) {
                ret[i][col] = head->val;
                head = head->next;
            }
            return;
        }
        if (j == r) {
            for (int row = i; row <= l && head; ++row) {
                ret[row][j] = head->val;
                head = head->next;
            }
            return;
        }
        for (int col = j; col < r && head; ++col) {
            ret[i][col] = head->val;
            head = head->next;
        }
        for (int row = i; row < l && head; row++) {
            ret[row][r] = head->val;
            head = head->next;
        }
        for (int col = r; col > j && head; --col) {
            ret[l][col] = head->val;
            head = head->next;
        }

        for (int row = l; row > i && head; --row) {
            ret[row][j] = head->val;
            head = head->next;
        }
        dfs(ret, i + 1, j + 1, l - 1, r - 1, head);
    }
};
int main() {
    Solution so;
    int m, n;
    ListNode* head;
    {
        head = create_linked_list({1, 2, 3, 4, 5, 6, 7, 8, 9});
        m = 3, n = 3;
        auto ret = so.spiralMatrix(m, n, head);
        printvector(ret);  // [[1,2,3],[8,9,4],[7,6,5]]
    }
    {
        head = create_linked_list({1, 2, 3, 4, 5, 6, 7, 8, 9});
        m = 1, n = 9;
        auto ret = so.spiralMatrix(m, n, head);
        printvector(ret);  // [[1,2,3,4,5,6,7,8,9]]
    }
    {
        head = create_linked_list({1});
        m = 1, n = 1;
        auto ret = so.spiralMatrix(m, n, head);
        printvector(ret);  // [[1]]
    }
    {
        head = create_linked_list({1});
        m = 2, n = 2;
        auto ret = so.spiralMatrix(m, n, head);
        printvector(ret);  // [[1,-1],[-1,-1]]
    }
    {
        head = create_linked_list({1});
        m = 3, n = 3;
        auto ret = so.spiralMatrix(m, n, head);
        printvector(ret);  // [[1,-1,-1],[-1,-1,-1],[-1,-1,-1]]
    }
    return 0;
}