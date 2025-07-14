#include <cstdio>
#include <iostream>
#include <map>
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_set<ListNode*> set;

   public:
    ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
        while (a) {
            set.insert(a);
            a = a->next;
        }

        while (b) {
            if (set.count(b))
                return b;
            b = b->next;
        }
        return nullptr;
    }
};

int main() {
    Solution so;
    vector<int> A, B;
    {
        A = {4, 1, 8, 4, 5};
        B = {5, 0, 1, 8, 4, 5};
        auto headA = create_linked_list(A);
        auto headB = create_linked_list(B);
        auto nodeA = get_linked_list_node(headA, 3);  // node with value 8
        auto nodeB = get_linked_list_node(headB, 3);  // node with value 1
        printf("nodeA: %d, nodeB: %d\n", nodeA->val, nodeB->val);
        nodeB->next = nodeA;  // create intersection
        auto res = so.getIntersectionNode(headA, headB);
        cout << (res ? res->val : -1) << endl;  // Output: 8
    }
    {
        A = {2, 6, 4};
        B = {1, 5};
        auto headA = create_linked_list(A);
        auto headB = create_linked_list(B);
        auto res = so.getIntersectionNode(headA, headB);
        cout << (res ? res->val : -1) << endl;  // Output: -1
    }
    return 0;
}