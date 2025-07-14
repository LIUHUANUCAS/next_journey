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

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;
        auto p = head;
        while (p != nullptr) {
            auto next = p->next;
            p->next = new Node(p->val);
            p->next->next = next;
            p = next;
        }
        p = head;
        while (p != nullptr) {
            auto next = p->next;
            if (p->random) {
                next->random = p->random->next;
            }
            p = next->next;
        }
        p = head;
        Node dummy(0);
        auto q = &dummy;
        while (p != nullptr) {
            auto next = p->next;
            q->next = next;
            p->next = next->next;
            p = p->next;
            q = next;
            q->next = nullptr;
        }
        return dummy.next;
    }
};

int main() {
    Solution so;

    return 0;
}