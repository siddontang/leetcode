#include "leetcode.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        int step = 1;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = NULL;
        ListNode* next = NULL;

        ListNode* n1 = NULL;
        ListNode* n2 = NULL;

        ListNode* first = NULL;
        ListNode* last = NULL;

        prev = &dummy;

        bool newLoop = true;

        while(true) {
            n1 = prev->next;
            n2 = n1;

            next = NULL;
            first = NULL;
            last = NULL;

            for(int i = 0; i < step; i++) {
                n1 = n2;
                n2 = n2->next;

                if(i == step - 1 || n2 == NULL) {
                    n1->next = NULL;
                    break;
                }
            }

            if(n2 == NULL && newLoop) {
                break;
            }

            newLoop = false;

            n1 = n2;
            for(int i = 0; i < step && n2 != NULL; i++) {
                next = n2->next;
                if(next == NULL) {
                    break;
                } else if (i == step - 1) {
                    n2->next = NULL;
                    break;
                }
                n2 = n2->next;
            }

            merge(prev->next, n1, &first, &last);   

            prev->next = first;
            last->next = next;

            prev = last; 

            if(next == NULL) {
                prev = &dummy;
                newLoop = true;
                step = 2 * step;
            }  
        }

        return dummy.next;
    }

    void merge(ListNode *n1, ListNode *n2, ListNode **first, ListNode **last) {        
        ListNode* head = NULL;
        ListNode* p = NULL;


        if(n2 == NULL || n1->val < n2->val) {
            head = n1;
            n1 = n1->next;
        } else {
            head = n2;
            n2 = n2->next;
        }

        p = head;

        while(n1 != NULL && n2 != NULL) {
            if(n1->val < n2->val) {
                p->next = n1;
                n1 = n1->next;
            } else {
                p->next = n2;
                n2 = n2->next;
            }

            p = p->next;
        }

        if(n1 != NULL) {
            p->next = n1;
        } else if(n2 != NULL) {
            p->next = n2;
        }

        while(true) {
            if(p->next == NULL) {
                *last = p;
                break;
            }
            p = p->next;
        } 

        *first = head;
    }
};

void printListNode(ListNode* a) {
    cout << "list nodes: ";
    while(a) {
        cout << a->val << "\t";
        a = a->next;
    }   
    cout << endl;
}

int main() {
    ListNode n1(6);
    ListNode n2(1);
    ListNode n3(9);

    ListNode n4(2);
    ListNode n5(7);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
 
    printListNode(&n1);


    Solution sln;
    ListNode* a = sln.sortList(&n1);

    printListNode(a);

    return 0;
}