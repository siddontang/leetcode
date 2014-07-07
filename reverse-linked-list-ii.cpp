#include "leetcode.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* p = &dummy;
        for(int i = 1; i < m; i++) {
            p = p->next;
        }

        ListNode* pm = p->next;

        for(int i = m; i < n; i++) {
            ListNode* n = pm->next;
            pm->next = n->next;
            n->next = p->next;
            p->next = n;
        }

        return dummy.next;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    printListNode(&n1);

    Solution sln;

    auto a = sln.reverseBetween(&n1, 2, 5);

    printListNode(&n1);

    return 0;
}