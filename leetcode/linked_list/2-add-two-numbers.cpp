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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return merge(l1, l2, 0);
    }
    ListNode* merge(ListNode* l1, ListNode* l2, int next) {
        if (l1 == nullptr && l2 == nullptr) {
            if (next == 0) {
                return nullptr;
            }
            return buildNode(l1, l2, next);
        }
        if (l1 == nullptr || l2 == nullptr) {
            int val = l1 == nullptr ? l2->val + next : l1->val + next;
            l1 = l1 == nullptr ? l1 : l1->next;
            l2 = l2 == nullptr ? l2 : l2->next;

            return buildNode(l1, l2, val);
        }
        return buildNode(l1->next, l2->next, l1->val + l2->val + next);
    }
    ListNode* buildNode(ListNode* l1, ListNode* l2, int val) {
        int next = val / 10;
        val %= 10;
        ListNode* res = new ListNode(val);
        res->next = merge(l1, l2, next);
        return res;
    }
};

int main() {
    Solution so;
    ListNode *l1, *l2;
    {
        l1 = create_linked_list({2, 4, 3});
        l2 = create_linked_list({5, 6, 4});
        auto res = so.addTwoNumbers(l1, l2);
        print_list(res);
    }

    {
        l1 = create_linked_list({0});
        l2 = create_linked_list({0});
        auto res = so.addTwoNumbers(l1, l2);
        print_list(res);
    }
    {
        l1 = create_linked_list({9, 9, 9, 9, 9, 9, 9});
        l2 = create_linked_list({9, 9, 9, 9});
        auto res = so.addTwoNumbers(l1, l2);
        print_list(res);
    }
    {
        l1 = create_linked_list({9, 9, 9, 9, 9, 9, 9});
        l2 = create_linked_list({1});
        auto res = so.addTwoNumbers(l1, l2);
        print_list(res);
    }
    {
        l1 = create_linked_list({9, 9});
        l2 = create_linked_list({1, 1});
        auto res = so.addTwoNumbers(l1, l2);
        print_list(res);
    }

    return 0;
}