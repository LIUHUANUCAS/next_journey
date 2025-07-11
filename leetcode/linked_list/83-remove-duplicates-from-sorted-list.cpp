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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(head->val - 1);
        dummy.next = head;
        dfs(head, &dummy);
        return dummy.next;
    }

    void dfs(ListNode* head, ListNode* pre) {
        if (head == nullptr)
            return;
        auto next = head->next;
        head->next = nullptr;
        if (head->val != pre->val) {
            pre->next = head;
            pre = head;
        }
        return dfs(next, pre);
    }
};
int main() {
    Solution so;
    vector<int> A;
    {
        A = {1, 1, 2, 3, 3};
        auto node = create_linked_list(A);
        auto res = so.deleteDuplicates(node);
        print_linked_list(res);
    }
    {
        A = {1, 1, 2, 2, 3, 3};
        auto node = create_linked_list(A);
        auto res = so.deleteDuplicates(node);
        print_linked_list(res);
    }
    {
        A = {1, 1, 1, 2, 3};
        auto node = create_linked_list(A);
        auto res = so.deleteDuplicates(node);
        print_linked_list(res);
    }
    {
        A = {1, 2, 3, 4, 5};
        auto node = create_linked_list(A);
        auto res = so.deleteDuplicates(node);
        print_linked_list(res);
    }
    return 0;
}