#include "leetcode.h"

class Solution {
public:
    int atoi(const char *str) {
        if(!str) {
            return 0;
        }

        long long res = 0;
        while(isspace(*str)) {
            str++;
        }

        bool neg = (*str == '-');
        if(*str == '-' || *str == '+') {
            str++;
        }

        while(isdigit(*str)) {
            int d = *str - '0';
            res = res * 10 + d;
            if(!neg && res > INT_MAX) {
                return INT_MAX;
            } else if(neg && -res < INT_MIN) {
                return INT_MIN;
            }

            str++;
        }

        return neg ? -res : res;
    }
};

int main() {
    Solution sln;

    cout << sln.atoi("123") << endl;
    cout << sln.atoi("-123") << endl;

    return 0;
}