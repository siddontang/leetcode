#include "leetcode.h"

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.empty()) {
            return;
        }

        int row = (int)board.size();
        int col = (int)board[0].size();
    

        for(int j = 0; j < col; j++) {
            if(board[0][j] == 'O') {
                board[0][j] = '#';
                dfs(board, 0, j, row, col);
            }

            if(board[row - 1][j] == 'O') {
                board[row - 1][j] = '#';
                dfs(board, row - 1, j, row, col);
            }
        }

        for(int i = 0; i < row; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(board, i, 0, row, col);
            }

            if(board[i][col - 1] == 'O') {
                board[i][col - 1] = '#';
                dfs(board, i, col - 1, row, col);
            }   
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char> > &board, int i, int j, int row, int column) {
        if(i > 1 && board[i - 1][j] == 'O') {
            board[i - 1][j] = '#';
            dfs(board, i - 1, j, row, column);
        }

        if(i < row - 1 && board[i + 1][j] == 'O') {
            board[i + 1][j] = '#';
            dfs(board, i + 1, j, row, column);
        }

        if(j > 1 && board[i][j - 1] == 'O') {
            board[i][j - 1] = '#';
            dfs(board, i, j - 1, row, column);
        }

        if(j < column - 1 && board[i][j + 1] == 'O') {
            board[i][j + 1] = '#';
            dfs(board, i, j + 1, row, column);
        }
    }
};

int main() {
    Solution sln;

    vector<vector<char> > board;

    board.resize(4);
    for(size_t i = 0; i < board.size(); i++) {
        board[i].resize(4, 'X');
    }

    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[3][1] = 'O';

    sln.solve(board);

    for(size_t i = 0; i < board.size(); i++) {
        for(size_t j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 'X') {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
}