#include "leetcode.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return check(p, q);
    }

    bool check(TreeNode* p, TreeNode* q) {
        if(p == NULL) {
            return q == NULL;
        } else if(q == NULL) {
            return p == NULL;
        } else if(p->val != q->val) {
            return false;
        }

        return check(p->left, q->left) && check(p->right, q->right);
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    

    n1.left = &n2;
    n1.right = &n3;
   
    TreeNode n4(1);
    TreeNode n5(2);
    TreeNode n6(2);
    

    n4.left = &n5;
    n4.right = &n6;

    Solution sln;

    cout << sln.isSameTree(&n1, &n4) << endl;

    return 0;
}