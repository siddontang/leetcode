#include "leetcode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) {
            return NULL;
        } else if (!headB) {
            return NULL;
        }

        ListNode* p = headA;
        while(p->next) {
            p = p->next;
        }

        p->next = headB;

        //is this O(1)???
        ListNode* tail = p;
        p = headA;

        headB = headA;
        while(headB->next && headB->next->next) {
            headA = headA->next;
            headB = headB->next->next;
            if(headA == headB) {
                break;
            }
        }

        if(!headA->next || !headB->next || !headB->next->next) {
            tail->next = NULL;
            return NULL;
        }

        headA = p;
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        tail->next = NULL;
        return headA;
    }
};

int main() {
    return 0;
}