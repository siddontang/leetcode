#include "leetcode.h"

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);  
    }

    vector<TreeNode*> generate(int start, int stop){
        vector<TreeNode*> vs;
        if(start > stop) {
            vs.push_back(NULL);
            return vs;
        }

        for(int i = start; i <= stop; i++) {
            auto l = generate(start, i - 1);
            auto r = generate(i + 1, stop);

            for(int j = 0; j < l.size(); j++) {
                for(int k = 0; k < r.size(); k++) {
                    TreeNode* n = new TreeNode(i);
                    n->left = l[j];
                    n->right = r[k];
                    vs.push_back(n);
                }
            }
        }

        return vs;
    }
};

int main() {
    return 0;
}