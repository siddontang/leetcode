#include "leetcode.h"

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> tokens;
        tokenize(s, tokens);

        std::reverse(tokens.begin(), tokens.end());

        s.clear();

        for(int i = 0; i < (int)tokens.size(); i++) {
            s.append(tokens[i]);
            if(i != int(tokens.size()) - 1) {
                s.append(" ");
            }
        }
    }

    void tokenize(const string& str, vector<string>& tokens, const string& delims = " \t") {
        string::size_type lastPos = str.find_first_not_of(delims, 0);
        string::size_type pos = str.find_first_of(delims, lastPos);

        while(string::npos != pos || string::npos != lastPos) {
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            lastPos = str.find_first_not_of(delims, pos);
            pos = str.find_first_of(delims, lastPos);
        }
    }
};

int main() {
    Solution sln;
    string s = "the sky is blue";

    cout << s << endl;

    sln.reverseWords(s);

    cout << s << endl;
    return 0;
}