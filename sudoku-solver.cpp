#include "leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        dfs(board);
    }

    bool dfs(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(int k = 0; k < 9; k++) {
                        board[i][j] = k + 1 + '0';
                        if(isValid(board, i, j) && dfs(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char> >& board, int x, int y) {
        char c = board[x][y];
        for(int i = 0; i < 9; i++) {
            if(i != x && board[i][y] == c) {
                return false;
            }
            if(i != y && board[x][i] == c) {
                return false;
            }
        }

        int xx = x / 3 * 3;
        int yy = y / 3 * 3;
        for(int i = xx; i < xx + 3; i++) {
            for(int j = yy; j < yy + 3; j++) {
                if(i != x && j != y && board[i][j] == c) {
                    return false;
                }
            }
        }

        return true;
    }

};

int main() {
    return 0;
}