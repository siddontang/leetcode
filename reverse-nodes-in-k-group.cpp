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
        ListNode* prev = &dummy;

        while(p) {
            prev = p;
            for(int i = 0; i < k; i++){
                p = p->next;
                if(!p) {
                    return dummy.next;
                }
            }

            p = reverse(prev, p->next);            
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* prev, ListNode* end) {
        ListNode* p = prev->next;

        while(p->next != end) {
            ListNode* n = p->next;
            p->next = n->next;
            n->next = prev->next;
            prev->next = n;
        }

        return p;
    }
};

int main() {
    Solution sln;

    ListNode* n = createListNode(vector<int>({1, 2, 3, 4, 5}));

    n = sln.reverseKGroup(n, 5);

    printListNode(n);

n = createListNode(vector<int>({1, 2, 3, 4}));

    n = sln.reverseKGroup(n, 2);

    printListNode(n);

    return 0;
}