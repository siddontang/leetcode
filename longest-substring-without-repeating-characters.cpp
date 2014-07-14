#include "leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);
        int start = 0;
        int maxV = numeric_limits<int>::min();
        for(int i = 0; i < s.size(); i++) {
            if(pos[s[i]] != -1) {
                maxV = max(maxV, i - start);
                start = pos[s[i]] + 1;
                i = pos[s[i]];
                pos.clear();
                pos.resize(256, -1);
                continue;
            }

            pos[s[i]] = i;
        }

        maxV = max(maxV, (int)s.size() - start);

        return maxV;
    }
};

int main() {
    Solution sln;

    cout << sln.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
    return 0;
}