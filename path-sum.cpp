#include "leetcode.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) {
            return false;
        }

        if(!root->left && !root->right && root->val == sum) {
            return true;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    TreeNode n1(5);
    TreeNode n2(4);
    TreeNode n3(8);
    TreeNode n4(11);
    TreeNode n5(13);
    TreeNode n6(4);
    TreeNode n7(7);
    TreeNode n8(2);
    TreeNode n9(1);

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n4.left = &n7;
    n4.right = &n8;

    n3.left = &n5;
    n3.right = &n6;

    n6.right = &n9;

    Solution sln;

    cout << sln.hasPathSum(&n1, 22) << endl;

    return 0;
}