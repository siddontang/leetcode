#include "leetcode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                return true;
            }
        }

        return false;
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
    n4.next = &n1;

    Solution sln;

    cout << sln.hasCycle(&n1) << endl;

    return 0;
}