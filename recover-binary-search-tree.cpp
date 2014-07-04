#include "leetcode.h"

class Solution {
public:
    vector<TreeNode*> ns;
    vector<int> vals;
    void recoverTree(TreeNode *root) {
        inorder(root);

        sort(vals.begin(), vals.end());
        for(int i = 0; i < ns.size(); i++) {
            ns[i]->val = vals[i];
        }
    }

    void inorder(TreeNode* node) {
        if(!node) {
            return;
        }

        inorder(node->left);
        ns.push_back(node);
        vals.push_back(node->val);
        inorder(node->right);
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