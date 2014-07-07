#include "leetcode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* p = head;
        while(p && p->next) {
            if(p->val != p->next->val) {
                prev = p;
                p = p->next;
            } else {
                int val = p->val;
                ListNode* n = p->next->next;
                while(n) {
                    if(n->val != val) {
                        break;
                    }
                    n = n->next;
                }

                prev->next = n;
                p = n;
            }
        }
        return dummy.next;
    }
};



int main() {
    Solution sln;
    ListNode* n1 = createListNode(vector<int>({1, 2, 3, 3, 4, 4, 5}));
    n1 = sln.deleteDuplicates(n1);
    printListNode(n1);

    n1 = createListNode(vector<int>({1, 1, 1, 2, 3}));
    n1 = sln.deleteDuplicates(n1);
    printListNode(n1);

    n1 = createListNode(vector<int>({1, 1, 1}));
    n1 = sln.deleteDuplicates(n1);
    printListNode(n1);
    return 0;
}