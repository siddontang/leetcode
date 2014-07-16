#include "leetcode.h"

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0; i < n - 1; i++) {
            s = gen(s);
        }
        return s;
    }

    string gen(string s) {
        string n;
        int len = s.size();
        int i = 0;
        while(i < len) {
            char c = s[i];
            char count = 1;
            while(i + count < len) {
                if(s[i + count] == c) {
                    count++;
                } else {
                    break;
                }
            }
            n.append(1, '0' + count);
            n.append(1, c);
            i += count;
        }
        return n;
    }
};

int main() {
    Solution sln;
    cout << sln.countAndSay(10) << endl;
    return 0;
}