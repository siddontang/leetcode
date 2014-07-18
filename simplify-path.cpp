#include "leetcode.h"

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) {
            return path;
        }

        vector<string> v;

        size_t pos = 0;
        size_t pos1 = 0;

        while(true) {
            pos = path.find_first_not_of('/', pos);
            if(pos == string::npos) {
                break;
            }

            pos1 = path.find_first_of('/', pos);
        
            string sub = path.substr(pos, pos1 - pos);
            pos = pos1;

            if(sub == ".") {
                continue;
            } else if(sub == "..") {
                if(!v.empty()) {
                    v.pop_back();
                    continue;
                }
            } else {
                v.push_back(sub);
            }
        }

        string s;
        string sep = "/";
        for(int i = 0; i < v.size(); i++) {
            s.append(sep);
            s.append(v[i]);
        }

        if(s.empty()) {
            return "/";
        }

        return s;
    }
};

int main() {
    Solution sln;

    cout << sln.simplifyPath("/a/./b/../../c/") << endl;

    return 0;
}