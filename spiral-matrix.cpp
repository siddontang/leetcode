#include "leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        if(matrix.empty() || matrix[0].empty()) {
            return v;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int cycle = (min(m, n) + 1) / 2;
    
        int a = n;
        int b = m;

        for(int i = 0; i < cycle; i++, a -= 2, b -= 2) {
            for(int c = i; c < i + a; c++) {
                v.push_back(matrix[i][c]);
            }

            for(int r = i + 1; r < i + b; r++) {
                v.push_back(matrix[r][i + a - 1]);
            }

            if(a == 1 || b == 1) {
                break;
            }

            for(int c = i + a - 2; c >= i; c--) {
                v.push_back(matrix[i + b - 1][c]);
            }

            for(int r = i + b - 2; r > i; r--) {
                v.push_back(matrix[r][i]);
            }
        }

        return v;
    }
};

int main() {
    Solution sln;

    vector<vector<int> > matrix(3, vector<int>(3, 0));
    for(int i = 0; i < 9; i++) {
        matrix[i / 3][i % 3] = i + 1;
    }

    auto a = sln.spiralOrder(matrix);

    printVector(a);

    return 0;
}