#include "leetcode.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<vector<bool> > dp;
        dp.resize(s1.size() + 1);
        for(int i = 0; i <= s1.size(); i++) {
            dp[i].resize(s2.size() + 1, false);
        }   

        dp[0][0] = true;

        for(int i = 1; i <= s1.size(); i++) {
            if(s1[i - 1] == s3[i - 1]) {
                dp[i][0] = true;
            }
        }   

        for(int j = 1; j <= s2.size(); j++) {
            if(s2[j - 1] == s3[j - 1]) {
                dp[0][j] = true;
            }
        }

        for(int i = 1; i <= s1.size(); i++) {
            char c1 = s1[i - 1];
            for(int j = 1; j <= s2.size(); j++) {
                char c2 = s2[j - 1];

                char c3 = s3[i + j - 1];

                if(c1 == c3) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if(c2 == c3) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[s1.size()][s2.size()];
    }
};

int main() {
    Solution sln;

    string s1 = "aabcc";
    string s2 = "dbbca";

    cout << sln.isInterleave(s1, s2, "aadbbcbcac") << endl;
    cout << sln.isInterleave(s1, s2, "aadbbbaccc") << endl;

    return 0;
}