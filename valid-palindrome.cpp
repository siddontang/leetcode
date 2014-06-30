#include "leetcode.h"

class Solution {
public:
    bool getChar(char c, char* p) {
        if(c >= 'a' && c <= 'z') {
            *p = c;
            return true;
        } else if (c >= 'A' && c <= 'Z') {
            c += 32;
            *p = c;
            return true;
        } else if (c >= '0' && c <= '9') {
            *p = c;
            return true;
        } else {
            return false;
        }
    }

    bool isPalindrome(string s) {
        if(s.empty()) {
            return true;
        }

        string dst;
        dst.reserve(s.size());

        for(int i = 0; i < (int)s.size();i++) {
            char b;
            if(getChar(s[i], &b)) {
                dst.append(1, b);
            }
        }

        int i = 0;
        int j = (int)dst.size() - 1;


        while(i < j) {
            if(dst[i] != dst[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution sln;

    cout << sln.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sln.isPalindrome("race a car") << endl;

    return 0;
}