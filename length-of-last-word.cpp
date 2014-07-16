#include "leetcode.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int count = 0;
        for(int i = len - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(count == 0) {
                    continue;
                } else {
                    return count;
                }
            }
            count++;
        }
        return count;
    }
};

int main() {
    return 0;
}