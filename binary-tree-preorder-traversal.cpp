#include "leetcode.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> vals;
        if(root == NULL) {
            return vals;
        }

        vector<TreeNode*> nodes;
        TreeNode* pre = NULL;

        nodes.push_back(root);

        while(!nodes.empty()) {
            TreeNode* n = nodes.back();
            vals.push_back(n->val);

            nodes.pop_back();

            if(n->right) {
                nodes.push_back(n->right);
            }
            if(n->left) {
                nodes.push_back(n->left);
            }
        }

        return vals;
    }
};

int main() {
    TreeNode n1(1);

    TreeNode n2(2);
    n1.right = &n2;

    TreeNode n3(3);
    n2.left = &n3;

    Solution sln;

    vector<int> a = sln.preorderTraversal(&n1);
    for(int i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i != a.size() - 1) {
            cout << "\t";
        } else {
            cout << endl;
        }
    }

    return 0;
}