#include "leetcode.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string c;

        if(a.size() > b.size()) {
            b = b.insert(0, a.size() - b.size(), '0');
        } else if(a.size() < b.size()) {
            a = a.insert(0, b.size() - a.size(), '0');
        }

        int cnt = 0;
        for(int i = a.size() - 1; i >= 0; i--) {
            int val = cnt + a[i] + b[i] - '0' - '0';
            c.push_back(val % 2 + '0');
            cnt = val / 2;
        }

        while(cnt > 0) {
            c.push_back(cnt % 2 + '0');
            cnt = cnt / 2;
        }

        reverse(c.begin(), c.end());
        return c;
    }
};

int main() {
    Solution sln;

    cout << sln.addBinary("11", "1") << endl;
    return 0;
}