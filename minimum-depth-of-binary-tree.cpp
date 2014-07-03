#include "leetcode.h"

class Solution {
public:
    int n;
    int minDepth(TreeNode *root) {
        if(!root) {
            return 0;
        }

        n = numeric_limits<int>::max();
        int d = 1;
    
        depth(root, d);
        return n;
    }

    void depth(TreeNode* node, int& d) {
        if(!node->left && !node->right) {
            n = min(n, d);
            return;
        }

        if(node->left) {
            d++;
            depth(node->left, d);
            d--;
        }

        if(node->right) {
            d++;
            depth(node->right, d);
            d--;
        }
    }
};

int main() {
    return 0;
}