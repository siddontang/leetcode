#include "leetcode.h"

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) {
            return NULL;
        }

        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        if(hLen < nLen) {
            return NULL;
        }

        for(int i = 0; i < hLen - nLen + 1; i++) {
            int j = 0;
            for(j = 0; j < nLen; j++) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if(j == nLen) {
                return &haystack[i];
            }
        }
        return NULL;
    }
};

int main() {
    return 0;
}