#include "leetcode.h"

class Solution {
public:
    vector<string> vals;
    int sumNumbers(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        vector<TreeNode*> vs;
        string val;

        dfs(vs, root, val);
    
        int num = 0;
        for(int i = 0; i < (int)vals.size(); i++) {
            num += atoi(vals[i].c_str());
        }
        return num;
    }

    void dfs(vector<TreeNode*>& vs, TreeNode* n, string& str) {
        vs.push_back(n);

        str.append(1, '0' + n->val);

        if(!n->left && !n->right) {
            vals.push_back(str);
            return;
        }

        if(n->left) {
            dfs(vs, n->left, str);
            vs.pop_back();
            str.erase(str.size() - 1);
        }

        if(n->right) {
            dfs(vs, n->right, str);
            vs.pop_back();
            str.erase(str.size() - 1);
        }
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.left = &n2;
    n1.right = &n3;

    Solution sln;

    cout << sln.sumNumbers(&n1) << endl;

    return 0;
}