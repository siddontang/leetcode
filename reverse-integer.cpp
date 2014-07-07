#include "leetcode.h"

class Solution {
public:
    int reverse(int x) {
        int neg = 1;
        if(x < 0) {
            neg = -1;
            x = -x;
        }

        int res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res * neg;
    }
};

int main() {
    Solution sln;

    cout << sln.reverse(123) << endl;
    cout << sln.reverse(-123) << endl;
}