#include "leetcode.h"

class Solution {
public:
    vector<string> v;

    vector<string> generateParenthesis(int n) {
        
        string s;

        dfs(n, n, s);

        return v;
    }

    void dfs(int left, int right, string& s) {
        if(left > right) {
            return;
        }
        
        if(left == 0 && right == 0) {
            v.push_back(s);
            return;
        }

        if(left > 0) {
            int l = s.size();
            s.append("(", 1);
            dfs(left - 1, right, s);
            s.erase(l);
        }

        if(right > 0) {
            int l = s.size();
            s.append(")", 1);
            dfs(left, right - 1, s);
            s.erase(l);
        }
    }
};

int main() {
    Solution sln;

    auto a = sln.generateParenthesis(3);

    printVector(a);

    return 0;
}