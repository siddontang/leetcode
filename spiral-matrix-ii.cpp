#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > v(n, vector<int>(n, 0));

        int a = n;
        int val = 1;
        for(int i = 0; i < n / 2; i++, a -= 2) {
            for(int c = i; c < i + a; c++) {
                v[i][c] = val++;
            }

            for(int r = i + 1; r < i + a; r++) {
                v[r][i + a - 1] = val++;
            }

            for(int c = i + a - 2; c >= i; c--) {
                v[i + a - 1][c] = val++;
            }

            for(int r = i + a - 2; r > i; r--) {
                v[r][i] = val++;
            }
        }

        if(n % 2) {
            v[n / 2][n / 2] = val;
        }

        return v;
    }
};

int main() {
    Solution sln;

    auto a = sln.generateMatrix(3);

    printVector2(a);

    return 0;
}