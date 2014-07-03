#include "leetcode.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root) {
            return true;
        }    

        int d = 1;
        return depth(root, d);
    }

    bool depth(TreeNode* node, int& d) {
        if(!node) {
            d = 0;
            return true;
        }
        int left, right;
        if(depth(node->left, left) && depth(node->right, right)) {
            if(abs(left - right) > 1) {
                return false;
            }

            d = 1 + max(left, right);
            return true;
        }   
        return false;     
    }
};

int main() {
    return 0;
}