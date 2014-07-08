#include "leetcode.h"

class Solution {
public:
    int climbStairs(int n) {
        int f1 = 2; 
        int f2 = 1;
        if(n == 1) {
            return f2;
        } else if(n == 2) {
            return f1;
        }

        int fn;
        for(int i = 3; i <= n; i++) {
            fn = f1 + f2;
            f2 = f1;
            f1 = fn;
        }
        return fn;
    }
};

int main() {
    Solution sln;
    cout << sln.climbStairs(4) << endl;
    return 0;
}