#include "leetcode.h"

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return;
        }

        int row = matrix.size();
        int col = matrix[0].size();
    
        bool zeroRow, zeroCol;
        zeroRow = false;
        zeroCol = false;
        for(int i = 0; i < col; i++) {
            if(matrix[0][i] == 0) {
                zeroRow = true;
                break;
            }
        }

        for(int j = 0; j < row; j++) {
            if(matrix[j][0] == 0) {
                zeroCol = true;
                break;
            }
        }

        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(zeroRow) {
            for(int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }

        if(zeroCol) {
            for(int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    return 0;
}