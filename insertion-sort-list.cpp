#include "leetcode.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode dummy(0);

        ListNode *n1 = NULL;
        ListNode *n2 = NULL;
        ListNode *next = NULL;

        while(head != NULL) {

            n1 = &dummy;
            n2 = dummy.next;

            while(n2 != NULL) {
                if(n2->val > head->val) {
                    break;
                }

                n1 = n2;
                n2 = n2->next;
            }

            next = head->next;
            
            n1->next = head;
            head->next = n2;

            head = next;
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