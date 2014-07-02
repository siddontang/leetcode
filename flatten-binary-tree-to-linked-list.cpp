#include "leetcode.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) {
            return;
        }

        vector<TreeNode*> ns;
        TreeNode dummy(0);

        TreeNode* n = &dummy;

        ns.push_back(root);

        while(!ns.empty()) {
            TreeNode* p = ns.back();
            ns.pop_back();

            n->right = p;
            n = p;


            if(p->right) {
                ns.push_back(p->right);
                p->right = NULL;
            }

            if(p->left) {
                ns.push_back(p->left);
                p->left = NULL;
            }
        }
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

    n1.left = &n2;
    n1.right = &n5;

    n2.left = &n3;
    n2.right = &n4;

    n5.right = &n6;

    Solution sln;

    sln.flatten(&n1);

    TreeNode* p = &n1;
    while(p) {
        cout << p->val << "\t";
        p = p->right;
    }

    cout << endl;
    return 0;
}