#include "leetcode.h"

class Solution {
public:
    bool isLeft(char c) {
        switch(c) {
            case '(':
            case '{':
            case '[':
                return true;
            default:
                return false;
        }
    }

    bool isPair(char c1, char c2) {
        return (c1 == '(' && c2 == ')') ||
               (c1 == '{' && c2 == '}') ||
               (c1 == '[' && c2 == ']');
    }

    bool isValid(string s) {
        if(s.empty()) {
            return true;
        }
        vector<char> v;
        v.push_back(s[0]);

        for(int i = 1; i < s.size(); i++) {
            switch(s[i]) {
                case '(':
                case '{':
                case '[':
                    if(v.empty() || isLeft(v.back())) {
                        v.push_back(s[i]);
                    } else {
                        return false;
                    }
                    break;
                case ')':
                case '}':
                case ']':
                    if(!v.empty() && isPair(v.back(), s[i])) {
                        v.pop_back();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return v.empty();
    }
};

int main() {
    Solution sln;

    cout << sln.isValid("()[]{}") << endl;
    cout << sln.isValid("()[{]}") << endl;

    return 0;
}