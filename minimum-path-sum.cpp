#include "leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        int dp[row][col];

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else if(j == 0) {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                } else if(i == 0) {
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[row - 1][col - 1];
    }
};

int main() {
    return 0;
}