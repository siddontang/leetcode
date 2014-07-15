#include "leetcode.h"

class Solution {
public:
    vector<string> letters;
    vector<string> vv;

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return vv;
        }

        letters.resize(10);
        letters[0] = ' ';
        letters[1] = "";
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";
    

        for(int i = 0; i < digits.size(); i++) {
            vv = merge(vv, digits[i]);
        }

        return vv;
    }

    vector<string> merge(const vector<string>& v, char digit) {
        string s = letters[digit - '0'];
        vector<string> vv;
        if(v.empty()) {
            for(int i = 0; i < s.size(); i++) {
                vv.push_back(string(1, s[i]));
            }
        } else {
            for(int i = 0; i < v.size(); i++) {
                for(int j = 0; j < s.size(); j++) {
                    vv.push_back(v[i] + s[j]);
                }
            }            
        }
        return vv;
    }
};

int main() {
    Solution sln;

    auto v = sln.letterCombinations("23");
    printVector(v);

    return 0;
}