#include "leetcode.h"

class Solution {
public:
    int num;
    int totalNQueens(int n) {
        vector<int> pos;

        num = 0;
        dfs(pos, 0, n);

        return num;
    }

    void dfs(vector<int> &pos, int k, int n) {
        if(n == k) {
            num++;
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

    auto a = sln.totalNQueens(4);

    cout << a << endl;

    return 0;
}