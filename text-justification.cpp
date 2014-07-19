#include "leetcode.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> v;
        int len = words.size();
        int i = 0;
        while(i < len) {
            int rowLen = 0;
            int j = i;
            while(j < len && rowLen + words[j].size() <= L) {
                rowLen += (words[j].size() + 1);
                j++;
            }

            if(j - i == 1) {
                v.push_back(words[i]);
                v.back().append(L - words[i].size(), ' ');
                i = j;
                continue;
            } 

            int charaLen = rowLen - (j - i);
            int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
            int leftSpace = j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i -1);
        
            string tmp;
            for(int k = i; k < j - 1; k++) {
                tmp += words[k];
                tmp.append(meanSpace, ' ');
                if(j < len && leftSpace > 0) {
                    tmp.push_back(' ');
                    leftSpace--;
                }
            }

            tmp += words[j - 1];
            if(leftSpace > 0) {
                tmp.append(leftSpace, ' ');
            }
            v.push_back(tmp);
            i = j;
        }

        return v;
    }
};

int main() {
    vector<string> w({"This", "is", "an", "example", "of", "text", "justification."});

    Solution sln;
    auto v = sln.fullJustify(w, 16);

    printVector(v);
    return 0;
}