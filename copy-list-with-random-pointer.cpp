#include "leetcode.h"

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
            return NULL;
        }       

        RandomListNode* n = NULL;
        RandomListNode* h = head;
        while(h) {
            RandomListNode* node = new RandomListNode(h->label);
            node->random = h->random;

            n = h->next;

            h->next = node;
            node->next = n;
            h = n;
        }
        h = head->next;
        while(h) {
            if(h->random != NULL) {
                h->random = h->random->next;
            }
            if(!h->next) {
                break;
            }
            h = h->next->next;
        }

        h = head;
        RandomListNode dummy(0);
        RandomListNode* p = &dummy;
        while(h) {
            n = h->next;
            p->next = n;
            p = n;
            RandomListNode* nn = n->next;
            h->next = n->next;
            h = n->next;
        }

        return dummy.next;
    }
};

int main() {
    RandomListNode n1(-1);
    Solution sln;
    RandomListNode* n2 = sln.copyRandomList(&n1);

    RandomListNode* h = n2;
    while(h) {
        cout << h->label << "\t" << h->random << endl;
        h = h->next;
    }

    return 0;
}