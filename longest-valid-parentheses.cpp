#include "leetcode.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxSum = 0;
        int i = 0;
        int len = s.size();
        vector<int> v;
        while(i < len) {
            if(s[i] == '(') {
                v.push_back(i);
            } else {
                if(!v.empty() && s[v.back()] == '(') {
                    v.pop_back();
                    maxSum = max(maxSum, i - (v.empty() ? -1 : v.back()));
                } else {
                    v.push_back(i);
                }
            }
            i++;
        }

        return maxSum;
    }
};

int main() {
    Solution sln;

    cout << sln.longestValidParentheses("()(())") << endl;

    return 0;
}