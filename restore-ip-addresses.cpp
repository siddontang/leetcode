#include "leetcode.h"

class Solution {
public:
    vector<string> vs;
    vector<string> ps;

    vector<string> restoreIpAddresses(string s) {
        ps.resize(4);
        dfs(s, 0, 0);
        return vs;
    }

    void dfs(const string& s, int start, int dep) {
        if(dep == 4) {
            if(start == s.size()) {
                string ss;
                for(int i = 0; i < ps.size(); i++) {
                    ss.append(ps[i]);
                    if(i != ps.size() - 1) {
                        ss.append(".");
                    }
                }
                vs.push_back(ss);
            }
            return;
        }

        for(int i = start; i < s.size(); i++) {
            auto sub = s.substr(start, i - start + 1);
            if(check(sub)) {
                ps[dep] = sub;

                dfs(s, i + 1, dep + 1);
            }
        }
    }

    bool check(const string& s) {
        switch(s.size()) {
            case 1:
                return s >= "0" && s <= "9";
            case 2:
                return s >= "10" && s <= "99";
            case 3:
                return s >= "100" && s <= "255";
            default:
                return false;
        }
    }
};

int main() {
    Solution sln;

    auto v = sln.restoreIpAddresses("25525511135");
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}