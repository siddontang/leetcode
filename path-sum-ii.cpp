#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > sums;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(!root) {
            return sums;
        }
        vector<int> vals;

        vals.push_back(root->val);
        checkSum(root, sum, vals);
        return sums;
    }

    void checkSum(TreeNode* node, int sum, vector<int>& vals) {
        if(!node->left && !node->right && node->val == sum) {
            sums.push_back(vals);
            return;
        }

        if(node->left) {
            vals.push_back(node->left->val);
            checkSum(node->left, sum - node->val, vals);
            vals.pop_back();
        }

        if(node->right) {
            vals.push_back(node->right->val);
            checkSum(node->right, sum - node->val, vals);
            vals.pop_back();
        }
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
    TreeNode n9(5);
    TreeNode n10(1);

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n4.left = &n7;
    n4.right = &n8;

    n3.left = &n5;
    n3.right = &n6;

    n6.left = &n9;
    n6.right = &n10;

    Solution sln;

    auto a = sln.pathSum(&n1, 22);

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}