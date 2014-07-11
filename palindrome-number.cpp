#include "leetcode.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int o = x;
        int n = 0;
        while(o != 0) {
            int d = o % 10;
            n = 10 * n + d;
            o = o / 10;
        } 

       return x == n;
    }
};

int main() {
    Solution sln;
    cout << sln.isPalindrome(121) << endl;
    return 0;
}