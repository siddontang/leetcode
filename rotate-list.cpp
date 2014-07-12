#include "leetcode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || k == 0) {
            return head;
        }

        int n = 1;
        ListNode* p = head;
        while(p->next) {
            p = p->next;
            n++;
        }
        
        k = n - k % n;
        p->next = head;

        for(int i = 0; i < k; i++) {
            p = p->next;
        }

        head = p->next;
        p->next = NULL;
        return head;
    }

    
};

int main() {
    Solution sln;

    ListNode* n1 = createListNode(vector<int>({1, 2, 3, 4, 5}));

    n1 = sln.rotateRight(n1, 2);

    printListNode(n1);

    return 0;
}