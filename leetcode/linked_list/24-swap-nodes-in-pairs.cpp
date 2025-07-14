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
    ListNode* swapPairs(ListNode* head) { return dfs(head); }
    ListNode* dfs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto next = head->next;
        head->next = dfs(next->next);
        next->next = head;
        return next;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 3, 4, 5};
        auto head = create_linked_list(A);
        auto res = so.swapPairs(head);
        print_list(res);
    }

    {
        A = {1, 2};
        auto head = create_linked_list(A);
        auto res = so.swapPairs(head);
        print_list(res);
    }
    return 0;
}