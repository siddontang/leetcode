#include "leetcode.h"

class Solution {
public:
    unordered_map<int, int> m;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()) {
            return NULL;
        }

        for(int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int s0, int e0, vector<int> &inorder, int s1, int e1) {
        if(s0 > e0 || s1 > e1) {
            return NULL;
        }

        int mid = m[preorder[s0]];

        TreeNode* root = new TreeNode(preorder[s0]);

        int num = mid - s1;

        root->left = build(preorder, s0 + 1, s0 + num, inorder, s1, mid - 1);
        root->right = build(preorder, s0 + num + 1, e0, inorder, mid + 1, e1);
    
        return root;
    }
};

int main() {
    
    return 0;
}