#include "leetcode.h"

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode* cur = 0;
        TreeNode* pre = 0;
        TreeNode* p1 = 0;
        TreeNode* p2 = 0;
        TreeNode* preCur = 0; 

        bool found = false;

        if(!root) {
            return;
        }

        cur = root;
        while(cur) {
            if(!cur->left) {
                if(preCur && preCur->val > cur->val) {
                    if(!found) {
                        p1 = preCur;
                        found = true;
                    }
                    p2 = cur;
                }

                preCur = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right && pre->right != cur) {
                    pre = pre->right;
                }

                if(!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    if(preCur->val > cur->val) {
                        if(!found) {
                            p1 = preCur;
                            found = true;
                        }
                        p2 = cur;
                    }
                    preCur = cur;
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }

        if(p1 && p2) {
            int t = p1->val;
            p1->val = p2->val;
            p2->val = t;
        }
    }
};

int main() {
    TreeNode n1(2);
    TreeNode n2(3);
    TreeNode n3(1);

    n1.left = &n2;
    n1.right = &n3;

    Solution sln;

    sln.recoverTree(&n1);

    cout << n1.val << "\t";
    cout << n2.val << "\t";
    cout << n3.val << endl;

    return 0;
}