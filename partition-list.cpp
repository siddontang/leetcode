#include "leetcode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1(0), dummy2(0);
        ListNode* p1 = &dummy1;
        ListNode* p2 = &dummy2;

        ListNode* p = head;
        while(p) {
            if(p->val < x) {
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }

        p2->next = NULL;
        p1->next = dummy2.next;
        return dummy1.next;
    }
};

int main() {
    Solution sln;

    ListNode* n1 = createListNode(
        vector<int>({1, 4, 3, 2, 5, 2}));

    n1 = sln.partition(n1, 3);

    printListNode(n1);

    return 0;
}