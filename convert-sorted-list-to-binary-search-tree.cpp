#include "leetcode.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head, NULL);
    }

    TreeNode* build(ListNode* start, ListNode* end) {
        if(start == end) {
            return NULL;
        }

        ListNode* fast = start;
        ListNode* slow = start;

        while(fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        node->left = build(start, slow);
        node->right = build(slow->next, end);

        return node;
    }
};

int main() {
    return 0;
}