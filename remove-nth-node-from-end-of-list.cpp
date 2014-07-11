#include "leetcode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head) {
            return head;
        }

        ListNode* p1 = head;
        ListNode* p2 = head;

        for(int i = 0; i < n; i++) {
            p1 = p1->next;
        }

        if(!p1) {
            head = head->next;
            return head;
        }

        while(p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }

        p2->next = p2->next->next;

        return head;
    }
};

int main() {
    Solution sln;
    ListNode* n1 = createListNode(vector<int>({1, 2, 3, 4, 5}));
    n1 = sln.removeNthFromEnd(n1, 2);
    printListNode(n1);

    ListNode* n2 = createListNode(vector<int>({1}));
    n2 = sln.removeNthFromEnd(n2, 1);
    printListNode(n2);

    return 0;
}