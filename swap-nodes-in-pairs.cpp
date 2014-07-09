#include "leetcode.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        ListNode* p = &dummy;
        dummy.next = head;

        while(p && p->next && p->next->next) {
            ListNode* n = p->next;
            ListNode* nn = p->next->next;
            p->next = nn;
            n->next = nn->next;
            nn->next = n;
            p = p->next->next;
        }

        return dummy.next;
    }
};

int main() {
    Solution sln;

    ListNode* n1 = createListNode(vector<int>({1, 2, 3, 4}));

    n1 = sln.swapPairs(n1);

    printListNode(n1);

    return 0;
}