#include "leetcode.h"

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1 || !head) {
            return head;
        }   

        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;

        while(p) {
            ListNode* prev = p;
            int i = 0;
            for(i = 0; i < k; i++) {
                p = p->next;
                if(!p) {
                    break;
                }
            }

            if(i == k) {
                ListNode* nn = p->next;
                p->next = NULL;
                ListNode* first = prev->next;

                prev->next = reverse(first);
                first->next = nn;
                p = first;
            } else{
                break;
            }
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* n1) {
        if(!n1) {
            return n1;
        }

        ListNode dummy(0);
        ListNode* p = &dummy;
        while(n1) {
            ListNode* nn = n1->next;

            ListNode* t = p->next;
            p->next = n1;
            n1->next = t;

            n1 = nn;
        }

        return dummy.next;
    }
};

int main() {
    Solution sln;

    ListNode* n = createListNode(vector<int>({1, 2, 3, 4, 5}));

    n = sln.reverseKGroup(n, 2);

    printListNode(n);

    return 0;
}