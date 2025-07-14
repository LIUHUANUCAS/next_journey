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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode small(0), large(0);
        ListNode *first = &small, *second = &large;
        while (head) {
            if (head->val < x) {
                first->next = head;
                first = first->next;
            } else {
                second->next = head;
                second = second->next;
            }
            head = head->next;
        }
        second->next = nullptr;
        first->next = large.next;
        return small.next;
    }
};
int main() {
    Solution so;

    return 0;
}