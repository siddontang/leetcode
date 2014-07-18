#include "leetcode.h"

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> v;
        if(S.empty() || L.empty()) {
            return v;
        }

        int len = L[0].size();

        unordered_map<string, int> m;
        for(int i = 0; i < L.size(); i++) {
            m[L[i]]++;
        } 

        int slen = S.size() - L.size() * len;

        for(int i = 0; i <= slen; i++) {
            unordered_map<string, int> mm(m);
            for(int j = i; j < S.size(); j+=len) {
                string s = S.substr(j, len);
                auto it = mm.find(s);
                if(it == mm.end()) {
                    break;
                } else {
                    it->second--;
                    if(it->second == 0) {
                        mm.erase(it);
                    }
                    if(mm.empty()) {
                        v.push_back(i);
                        break;
                    }
                }
            }
        }

        return v;
    }
};

int main() {
    Solution sln;

    vector<string> s({"foo", "bar"});

    auto v = sln.findSubstring("barfoothefoobarman", s);

    printVector(v);

    return 0;
}