#include "leetcode.h"

class Solution {
public:
    vector<vector<string> > vv;
    vector<vector<string> > solveNQueens(int n) {
        vector<int> pos;

        dfs(pos, 0, n);

        return vv;
    }

    void dfs(vector<int> &pos, int k, int n) {
        if(n == k) {
            int l = pos.size();
            vector<string> v(l, string(l, '.'));
            for(int i = 0; i < l; i++) {
                v[i][pos[i]] = 'Q';
            }
            vv.push_back(v);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isValid(pos, k, i)) {
                pos.push_back(i);
                dfs(pos, k + 1, n);
                pos.pop_back();
            }
        }
    }

    bool isValid(vector<int> &pos, int row, int col) {
        for(int j = 0; j < pos.size(); j++) {
            if(pos[j] == col || abs(j - row) == abs(pos[j] - col)) {
                return false;
            }   
        }
        return true;
    }
};

int main() {
    Solution sln;

    auto a = sln.solveNQueens(4);

    printVector2(a);

    return 0;
}