#include "leetcode.h"

class Solution {
public:
    unordered_map<int, int> m;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.empty()) {
            return NULL;
        }   

        for(int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1, 
            postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, int s0, int e0, 
        vector<int>& postorder, int s1, int e1) {
        if(s0 > e0 || s1 > e1) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[e1]);

        int mid = m[postorder[e1]];
        int num = mid - s0;

        root->left = build(inorder, s0, mid - 1, postorder, s1, s1 + num - 1);
        root->right = build(inorder, mid + 1, e0, postorder, s1 + num, e1 - 1);

        return root;
    }
};

int main() {
    return 0;
}