#include "leetcode.h"

class Solution {
public:
    double power(double x, int n) {
        if(n == 0) {
            return 1;
        } else if(n == 1) {
            return x;
        }

        double v = pow(x, n / 2);
        if(n % 2 == 0) {
            return v * v;
        } else {
            return v * v * x;
        }
    }

    double pow(double x, int n) {
        if(n < 0) {
            return 1.0 / power(x, -n);
        } else {
            return power(x, n);
        }
    }
};

int main() {
    Solution sln;
    cout << sln.pow(2, 2) << endl;
    return 0;
}