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
   public:
    ListNode* reverseKGroup(ListNode* head, int k) { return dfs(head, k); }
    ListNode* dfs(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int i = 0;
        ListNode dummy(0), *next = head;
        auto p = &dummy, cur = head;
        for (i = 0; i < k && cur != nullptr; ++i) {
            next = cur->next;
            cur->next = p->next;  // break the link
            p->next = cur;        // link to dummy
            cur = next;           // move to the next node
        }
        if (i < k) {  // not enough nodes to reverse
            return reverse(dummy.next);
        }
        head->next = dfs(next, k);
        return dummy.next;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto r = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return r;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        auto head = create_linked_list(A);
        auto res = so.reverseKGroup(head, 6);
        print_list(res);
        // print_list(so.reverse(head->next->next));
    }

    {
        A = {1, 2, 3, 4, 5};
        auto head = create_linked_list(A);
        auto res = so.reverseKGroup(head, 3);
        print_list(res);
    }

    {
        A = {1};
        auto head = create_linked_list(A);
        auto res = so.reverseKGroup(head, 1);
        print_list(res);
    }
    return 0;
}