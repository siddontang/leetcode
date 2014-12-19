#include "leetcode.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode dummy(0);

        ListNode* p = &dummy;

        ListNode* cur = head;
        while(cur) {
            p = &dummy;
            
            while(p->next && p->next->val <= cur->val) {
                p = p->next;
            }

            ListNode* n = p->next;
            p->next = cur;

            cur = cur->next;
            p->next->next = n;
        }

        return dummy.next;
    }
};

int main() {
    ListNode n1(6);
    ListNode n2(1);
    ListNode n3(9);

    ListNode n4(2);
    ListNode n5(7);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Solution sln;

    ListNode * a = sln.insertionSortList(&n1);

    printListNode(a);

    return 0;
}