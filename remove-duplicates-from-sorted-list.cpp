#include "leetcode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) {
            return head;
        }

        int val = head->val;
        ListNode* p = head;
        while(p && p->next) {
            if(p->next->val != val) {
                val = p->next->val;
                p = p->next;
            } else {
                ListNode* n = p->next->next;
                p->next = n;
            }
        }

        return head;
    }
};



int main() {
    Solution sln;
    ListNode* n1 = createListNode(vector<int>({1, 1, 2}));
    n1 = sln.deleteDuplicates(n1);
    printListNode(n1);

    n1 = createListNode(vector<int>({1, 1, 2, 3, 3}));
    n1 = sln.deleteDuplicates(n1);
    printListNode(n1);

    n1 = createListNode(vector<int>({1, 1, 1}));
    n1 = sln.deleteDuplicates(n1);
    printListNode(n1);
    return 0;
}