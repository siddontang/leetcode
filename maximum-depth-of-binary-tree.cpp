#include "leetcode.h"

class Solution {
public:
    int num;
    int maxDepth(TreeNode *root) {
        if(!root) {
            return 0;
        }

        num = numeric_limits<int>::min();
        travel(root, 1);
        return num;
    }

    void travel(TreeNode* node, int level) {
        if(!node->left && !node->right) {
            num = max(num, level);
            return;
        }

        if(node->left) {
            travel(node->left, level + 1);
        }

        if(node->right) {
            travel(node->right, level + 1);
        }
    }
};

int main() {
    return 0;
}