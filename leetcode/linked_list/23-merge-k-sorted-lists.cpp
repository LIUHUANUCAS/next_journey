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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
                       function<bool(ListNode*, ListNode*)>>
            pq([](ListNode* a, ListNode* b) { return a->val > b->val; });
        for (auto& list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
int main() {
    Solution so;
    vector<vector<int>> lists;
    {
        lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
        auto listsNode = create_linked_list(lists);
        auto res = so.mergeKLists(listsNode);
        print_linked_list(res);
    }
    return 0;
}