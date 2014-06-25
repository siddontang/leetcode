#include "leetcode.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vals;
        if(root == NULL) {
            return vals;
        }

        vector<TreeNode*> nodes;
        TreeNode* p = root;
        while(p || !nodes.empty()) {
            while(p) {
                nodes.push_back(p);
                p = p->left;
            }

            if(!nodes.empty()) {
                p = nodes.back();
                vals.push_back(p->val);
                nodes.pop_back();
                p = p->right;
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

    vector<int> a = sln.inorderTraversal(&n1);
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