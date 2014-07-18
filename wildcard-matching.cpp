#include "leetcode.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = NULL;
        const char *ss = s;
        while(*s) {
            if(*p == '?' || *p == *s) {
                s++;
                p++;
                continue;
            }
            if(*p == '*') {
                star = p++;
                ss = s;
                continue;
            }
            if(star) {
                p = star + 1;
                s = ++ss;
                continue;
            }
            return false;
        }
            
        while(*p == '*') {
            p++;
        }
        return !*p;
    }
};

int main() {
    Solution sln;

    // cout << sln.isMatch("aa", "a") << endl;
    // cout << sln.isMatch("aa", "aa") << endl;
    // cout << sln.isMatch("aaa", "aa") << endl;
    // cout << sln.isMatch("aa", "*") << endl;
    // cout << sln.isMatch("aa", "a*") << endl;
    // cout << sln.isMatch("ab", "?*") << endl;
    // cout << sln.isMatch("aab", "c*a*b") << endl;
    // cout << sln.isMatch("", "*") << endl;
    // cout << sln.isMatch("c", "*?*") << endl;
    // cout << sln.isMatch("c", "**?*") << endl;
    // cout << sln.isMatch("", "") << endl;
    cout << sln.isMatch("b", "*?*?*") << endl;
    cout << sln.isMatch("hi", "*?") << endl;

    return 0;
}