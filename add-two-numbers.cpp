#include "leetcode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;

        int cn = 0;

        while(l1 && l2) {
            int val = cn + l1->val + l2->val;
            cn = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int val = cn + l1->val;
            cn = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
        }

        while(l2) {
            int val = cn + l2->val;
            cn = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            l2 = l2->next;
        }

        if(cn != 0) {
            p->next = new ListNode(cn);
            p = p->next;
        }

        return dummy.next;
    }
};

int main() {
    Solution sln;

    ListNode* n1 = createListNode(vector<int>({1, 8}));
    ListNode* n2 = createListNode(vector<int>({0}));

    ListNode* n = sln.addTwoNumbers(n1, n2);
    printListNode(n);
    return 0;
}