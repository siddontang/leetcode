#include "leetcode.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vals;
        if(root == NULL) {
            return vals;
        }

        vector<TreeNode*> nodes;
        TreeNode* pre = NULL;

        nodes.push_back(root);

        while(!nodes.empty()) {
            TreeNode* p = nodes.back();
            if((p->left == NULL && p->right == NULL) || 
                (pre != NULL && (pre == p->left || pre == p->right))) {
                vals.push_back(p->val);
                nodes.pop_back();
                pre = p;
            } else {
                if(p->right != NULL) {
                    nodes.push_back(p->right);
                }

                if(p->left != NULL) {
                    nodes.push_back(p->left);
                }
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

    vector<int> a = sln.postorderTraversal(&n1);
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