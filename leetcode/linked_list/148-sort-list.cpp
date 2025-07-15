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
   public:
    ListNode* sortList(ListNode* head) { return sort(head); }
    ListNode* sort(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto fast = head, slow = head->next;
        while (slow && slow->next) {
            fast = fast->next;
            slow = slow->next->next;
        }

        auto next = fast->next;
        fast->next = nullptr;
        head = sort(head);
        next = sort(next);
        return merge(head, next);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        auto node = l1;
        if (l1->val <= l2->val) {
            node = l1;
            l1 = l1->next;
        } else {
            node = l2;
            l2 = l2->next;
        }
        node->next = merge(l1, l2);
        // print_linked_list(node);
        return node;
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {4, 2, 1, 3};
        printvector(A);
        auto head = create_linked_list(A);
        auto res = so.sortList(head);
        print_linked_list(res);
    }
    {
        A = {-1, 5, 3, 4, 0};
        auto head = create_linked_list(A);
        auto res = so.sortList(head);
        print_linked_list(res);
    }
    return 0;
}