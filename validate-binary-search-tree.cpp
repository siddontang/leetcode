#include "leetcode.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return valid(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    bool valid(TreeNode* node, int minVal, int maxVal) {
        if(!node) {
            return true;
        }

        if(node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return valid(node->left, minVal, node->val) && 
        valid(node->right, node->val, maxVal);
    }
};

int main() {
    return 0;
}