#include "leetcode.h"

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = numeric_limits<int>::min();
        int sum = getMax(root, maxSum);
        return max(sum, maxSum);
    }

    int getMax(TreeNode* node, int &sum) {
        if(!node) {
            return 0;
        }

        int left = getMax(node->left, sum);
        int right = getMax(node->right, sum);

        int val = node->val;

        if(left > 0) {
            val += left;
        }
        if(right > 0) {
            val += right;
        }

        sum = std::max(sum, val);
        return max(node->val, max(node->val + left, node->val + right));
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);

    n1.left = &n2;
    n1.right = &n3;

    Solution sln;

    cout << sln.maxPathSum(&n1) << endl;

    return 0;
}