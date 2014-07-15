#include "leetcode.h"

class Solution {
public:
    string convert(string s, int nRows) {
        string r;
        int n = 2 * nRows - 2;
        if(nRows <= 1) {
            return s;
        }

        for(int i = 0; i < nRows; i++) {
            for(int j = 0, index = i; index < s.size();
                j++, index = n * j + i) {
                r.append(1, s[index]);
                if(i == 0 || i == nRows - 1) {
                    continue;
                }

                if(index + (nRows - i - 1) * 2 < s.size()) {
                    r.append(1, s[index + (nRows - i - 1) * 2]);
                }
            }
        }
        return r;
    }
};

int main() {
    Solution sln;
    cout << sln.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}