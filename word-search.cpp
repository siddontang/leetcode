#include "leetcode.h"

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty()) {
            return true;
        }

        if(board.empty() || board[0].empty()) {
            return false;
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> > &board, string word, int level, int x, int y) {
        if(level == word.size() - 1) {
            return true;
        }

        char c = board[x][y];
        board[x][y] = '#';

        char w = word[level + 1];
        if(x - 1 >= 0 && board[x - 1][y] == w) {
            if(dfs(board, word, level + 1, x - 1, y)) {
                return true;
            }
        }

        if(x + 1 < board.size() && board[x + 1][y] == w) {
            if(dfs(board, word, level + 1, x + 1, y)) {
                return true;
            }
        }

        if(y - 1 >= 0 && board[x][y - 1] == w) {
            if(dfs(board, word, level + 1, x, y - 1)) {
                return true;
            }
        }   

        if(y + 1 < board[0].size() && board[x][y + 1] == w) {
            if(dfs(board, word, level + 1, x, y + 1)) {
                return true;
            }
        }

        board[x][y] = c;
        return false;
    }
};

int main() {
    return 0;
}