#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vals;
    vector<vector<int> > levelOrder(TreeNode *root) {
        build(root, 1);
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
    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    TreeNode n4(15);
    TreeNode n5(7);

    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    Solution sln;

    auto a = sln.levelOrder(&n1);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}