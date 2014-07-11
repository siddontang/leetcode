#include "leetcode.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s;
        if(strs.empty()) {
            return s;
        }

        int pos = 0;
        char c;

        while(1) {
            for(int i = 0; i < strs.size(); i++) {
                if(i == 0) {
                    if(strs[0].size() > pos) {
                        c = strs[0][pos];
                    } else {
                        return s;
                    }
                } else {
                    if(strs[i].size() == pos || strs[i][pos] != c) {
                        return s;
                    }
                }
            }

            pos++;
            s.append(1, c);

        }
        return s;
    }
};

int main() {
    Solution sln;

    vector<string> strs({"abcde", "abcd"});

    cout << sln.longestCommonPrefix(strs) << endl;

    return 0;
}