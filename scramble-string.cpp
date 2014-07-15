#include "leetcode.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }

        char v =  0;
        for(int i = 0; i < s1.size(); i++) {
            v ^= (s1[i] ^ s2[i]);
        }

        if(v != 0) {
            return false;
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