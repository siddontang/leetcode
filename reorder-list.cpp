#include "leetcode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;
        slow->next = NULL;


        ListNode dummy(0);
        while(fast) {
            ListNode* n = dummy.next;
            dummy.next = fast;
            ListNode* nn = fast->next;
            fast->next = n;
            fast = nn;
        }

        slow = head;
        fast = dummy.next;

        while(slow) {
            if(fast != NULL) {
                ListNode* n = slow->next;
                slow->next = fast;
                ListNode* nn = fast->next;
                fast->next = n;
                fast = nn;
                slow = n;
            } else {
                break;
            }
        }
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution sln;

    sln.reorderList(&n1);

    printListNode(&n1);

    return 0;
}