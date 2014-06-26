#include "leetcode.h"

class Solution {
public:
    bool wordBreak(string s, set<string> &dict) {
        int len = (int)s.size();
        vector<bool> words(len + 1, false);
        words[0] = true;

        for(int i = 1; i <= len; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(words[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    words[i] = true;
                    break;
                }
            }
        }
        return words[len];
    }
};

int main() {
    Solution sln;
    set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    cout << sln.wordBreak("leetcode", dict) << endl;
    cout << sln.wordBreak("leetecode", dict) << endl;
    return 0;
}