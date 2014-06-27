#include "leetcode.h"

class Solution {
public:
    int minCut(string s) {
        if(s.empty()) {
            return 0;
        }
        
        vector<vector<bool> > vv;
        vv.resize(s.size());
        for(size_t i = 0; i < vv.size(); i++) {
            vv[i].resize(s.size(), false);
        }

        vector<int> cuts;
        cuts.resize(s.size() + 1, 0);
        for(size_t i = 0; i < s.size(); i++) {
            cuts[i] = s.size() - i;
        }

        for(int i = (int)s.size() - 1; i >= 0; i--) {
            for(int j = i; j < (int)s.size(); j++) {
                if( (s[i] == s[j] && j - i < 2)  || (s[i] == s[j] && vv[i + 1][j - 1])) {
                    vv[i][j] = true;

                    cuts[i] = min(cuts[i], cuts[j + 1] + 1);
                }
            }
        }

        return cuts[0] - 1;
    }
};

int main() {
    Solution sln;

    cout << sln.minCut("aab") << endl;

    return 0;
}