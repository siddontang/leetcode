#include "leetcode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;

        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(fast);

        return merge(p1, p2);
    }

    ListNode *merge(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        } else if (!l1 && !l2) {
            return NULL;
        }

        ListNode dummy(0);
        ListNode* p = &dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

        if(l1) {
            p->next = l1;
        } else if(l2){
            p->next = l2;
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
 
    printListNode(&n1);


    Solution sln;
    ListNode* a = sln.sortList(&n1);

    printListNode(a);

    return 0;
}