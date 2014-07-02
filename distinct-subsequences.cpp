#include "leetcode.h"

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();

        if(m == 0) {
            return 0;
        } else if(n == 0) {
            return 1;
        }

        vector<vector<int> > dp;
        dp.resize(m + 1);
        for(int i = 0; i < m + 1; i++) {
            dp[i].resize(n + 1);
            dp[i][0] = 1;
        }

        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i -1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    return 0;
}