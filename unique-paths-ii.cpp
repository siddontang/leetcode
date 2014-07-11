#include "leetcode.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];

        dp[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);

        for(int i = 1; i < m; i++) {
            dp[i][0] = ((dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0);
        }

        for(int j = 1; j < n; j++) {
            dp[0][j] = ((dp[0][j - 1] == 1 && obstacleGrid[0][j] == 0) ? 1 : 0);
        }


        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int > > vv(1, vector<int>(1, 0));
    vv[0][0] = 0;

    Solution sln;

    cout << sln.uniquePathsWithObstacles(vv) << endl;

    return 0;
}