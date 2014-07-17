#include "leetcode.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> m;
        vector<string> r;
        if(strs.size() <= 1) {
            return r;
        }

        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());

            auto it = m.find(s);
            if(it == m.end()) {
                m.insert(make_pair(s, i));
            } else {
                if(it->second >= 0) {
                    r.push_back(strs[it->second]);
                    it->second = -1;
                }
                r.push_back(strs[i]);
            }
        }
        return r;
    }
};

int main() {
    return 0;
}