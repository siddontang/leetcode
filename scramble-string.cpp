#include "leetcode.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }

        int v1 = 0;
        int v2 = 0;
        for(int i = 0; i < s1.size(); i++) {
            v1 += s1[i];
            v2 += s2[i];
        }

        if(v1 != v2) {
            return false;
        }

        if(s1.size() == 1) {
            return true;
        }

        for(int i = 1; i < s1.size(); i++) {
            string s11 = s1.substr(0, i); 
            string s12 = s1.substr(i, s1.size() - i);

            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i, s1.size() - i);

            if(isScramble(s11, s21) && isScramble(s12, s22)) {
                return true;
            }

            s21 = s2.substr(s2.size() - i, i);
            s22 = s2.substr(0, s2.size() - i);

            if(isScramble(s11, s21) && isScramble(s12, s22)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    return 0;
}