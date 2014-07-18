#include "leetcode.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((double)dividend);
        long long b = abs((double)divisor);
        int r = 0;
        while(a >= b) {
            long long t = b;
            for(int i = 1; a >= t; i <<= 1, t <<= 1) {
                a -= t;
                r += i;
            }
        }
        return ((dividend < 0) ^ (dividend < 0)) ? -r : r;
    }
};

int main() {
    Solution sln;

    cout << sln.divide(-2147483648, 1) << endl;

    return 0;
}