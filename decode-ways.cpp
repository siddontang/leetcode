#include "leetcode.h"

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if(isValid(s[0])) {
            dp[1] = 1;
        }

        for(int i = 2; i <= n; i++) {
            if(isValid(s[i - 1])) {
                dp[i] = dp[i - 1];
            } 
            if(isValid(s[i - 2], s[i - 1])) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

    bool isValid(char c) {
        return c != '0';
    }

    bool isValid(char c1, char c2) {
        if(c1 == '1') {
            return true;
        } else if(c1 == '2') {
            return c2 >= '0' && c2 <= '6';
        } else {
            return false;
        }
    }
};

int main() {
    Solution sln;
    cout << sln.numDecodings("10") << endl;
    return 0;
}