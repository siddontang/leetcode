#include "leetcode.h"

class Solution {
public:
    int toNumber(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i > 0 && toNumber(s[i]) > toNumber(s[i - 1])) {
                res += toNumber(s[i]) - 2 * toNumber(s[i - 1]);
            } else {
                res += toNumber(s[i]);
            }
        }   

        return res; 
    }
};

int main() {
    return 0;
}