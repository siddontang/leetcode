#include "leetcode.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        while(l1 && l2) {
            int val1 = l1->val;
            int val2 = l2->val;
            if(val1 < val2) {
                p->next = l1;
                p = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }

        if(l1) {
            p->next = l1;
        } else if(l2) {
            p->next = l2;
        }

        return dummy.next;
    }
};

int main() {
    return 0;
}