#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vals;
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        build(root, 1);

        for(int i = 1; i < vals.size(); i+=2) {
            reverse(vals[i].begin(), vals[i].end());
        }

        return vals;
    }

    void build(TreeNode* node, int level) {
        if(!node) {
            return;
        }

        if(vals.size() <= level - 1) {
            vals.push_back(vector<int>());
        }

        vals[level - 1].push_back(node->val);

        if(node->left) {
            build(node->left, level + 1);
        }

        if(node->right) {
            build(node->right, level + 1);
        }
    }
};

int main() {
    return 0;
}