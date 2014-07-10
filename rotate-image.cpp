#include "leetcode.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n == 0) {
            return ;
        }

        int a = n;
        for(int i = 0; i < n / 2; i++, a -= 2) {
            int m = a - 1;
            for(int j = 0; j < m; j++) {
                int t = matrix[i][i + j];
                matrix[i][i +j] = matrix[i + m - j][i];
                matrix[i + m - j][i] = matrix[i + m][i + m -j];
                matrix[i + m][i + m - j] = matrix[i + j][i + m];
                matrix[i + j][i + m] = t;
            }
        }
    }
};

int main() {
    return 0;
}