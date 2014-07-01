#include "leetcode.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) {
            return;
        }

        TreeLinkNode* p = root;
        TreeLinkNode* left = NULL;
        while(p) {
            if(!left) {
                left = p->left;
            }
            if(p->left) {
                p->left->next = p->right;
            } else {
                break;
            }

            if(p->next) {
                p->right->next = p->next->left;
                p = p->next;
                continue;
            } else {
                p = left;
                left = NULL;
            }
        }
    }
};

int main() {
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    TreeLinkNode n6(6);
    TreeLinkNode n7(7);
    
    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n3.left = &n6;
    n3.right = &n7;

    Solution sln;

    sln.connect(&n1);

    TreeLinkNode* p = &n1;
    TreeLinkNode* next = p->next;
    while(p) {
        cout << p->val << "\t";
        next = p->next;
        while(next) {
            cout << next->val << "\t";
            next = next->next;
        }
        cout << endl;
        p = p->left;
    }

    return 0;
}