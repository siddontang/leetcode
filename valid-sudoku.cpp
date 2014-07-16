#include "leetcode.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> flag(10, false);

        for(int i = 0; i < 9; i++) {
            fill(flag.begin(), flag.end(), false);
            for(int j = 0; j < 9; j++) {
                if(!setFlag(flag, board[i][j])) {
                    return false;
                }
            }
        }

        for(int j = 0; j < 9; j++) {
            fill(flag.begin(), flag.end(), false);

            for(int i = 0; i < 9; i++) {
                if (!setFlag(flag, board[i][j]))
                {
                    return false;
                }
            }
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                fill(flag.begin(), flag.end(), false);
                
                for(int m = 0; m < 3; m++) {
                    for(int n = 0; n < 3; n++) {
                        if(!setFlag(flag, board[i * 3 + m][j * 3 + n])){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool setFlag(vector<bool>& flag, char c) {
        if(c == '.') {
            return true;
        }

        int i = c - '0';
        if(flag[i]) {
            return false;
        } else {
            flag[i] = true;
            return true;
        }
    }
};

int main() {
    return 0;
}