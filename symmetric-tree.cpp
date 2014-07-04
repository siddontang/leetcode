#include "leetcode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) {
            return true;
        }

        return check(root->left, root->right);
    }

    bool check(TreeNode* left, TreeNode* right) {
        if(left == NULL) {
            return right == NULL;
        } else if(right == NULL) {
            return left == NULL;
        } else if(left->val != right->val) {
            return false;
        }

        return check(left->left, right->right) && check(left->right, right->left);
    }
    
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    

    n1.left = &n2;
    n1.right = &n3;
   

    Solution sln;

    cout << sln.isSymmetric(&n1) << endl;

    return 0;
}