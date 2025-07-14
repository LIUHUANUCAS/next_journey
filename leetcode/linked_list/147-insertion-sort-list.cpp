#include <cstdio>
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
   public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-5001);
        ListNode *p = head, *q;
        while (p) {
            q = &dummy;
            while (q->next) {
                if (q->val <= p->val && p->val <= q->next->val) {
                    break;
                } else {
                    q = q->next;
                }
            }

            if (q->next == nullptr) {
                q->next = p;
                p = p->next;
                q->next->next = nullptr;
            } else {
                auto x = p->next;
                p->next = q->next;
                q->next = p;
                p = x;
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution so;

    return 0;
}