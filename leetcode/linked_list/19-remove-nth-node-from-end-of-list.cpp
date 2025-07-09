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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *p = head, *q = &dummy;
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
        while (p) {
            p = p->next;
            q = q->next;
        }

        q->next = q->next->next;
        return dummy.next;
    }
};

int main() {
    Solution so;
    vector<int> A;
    int n;
    {
        A = {1, 2, 3, 4, 5};
        n = 2;
        ListNode* head = create_linked_list(A);
        ListNode* res = so.removeNthFromEnd(head, n);
        print_list(res);
    }
    {
        A = {1};
        n = 1;
        ListNode* head = create_linked_list(A);
        ListNode* res = so.removeNthFromEnd(head, n);
        print_list(res);
    }
    {
        A = {1, 2};
        n = 2;
        ListNode* head = create_linked_list(A);
        ListNode* res = so.removeNthFromEnd(head, n);
        print_list(res);
    }
    return 0;
}