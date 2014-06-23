#include "leetcode.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
           
    }
};

int main() {
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(1);

    n1.next = &n2;
    n2.next = &n3;

    Solution sln;
    ListNode* a = sln.sortList(&n1);

    while(a) {
        cout << a->val << endl;
        a = a->next;
    }

    return 0;
}