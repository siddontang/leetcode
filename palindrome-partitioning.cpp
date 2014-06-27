#include "leetcode.h"

class Solution {
public:
    vector<vector<string> > vvs;
    
    vector<vector<string> > partition(string s) {
        vector<string> vs;
        split(s, 0, vs);
        return vvs;
    }

    void split(const string&s, size_t start, vector<string>& vs) {
        if(start == s.size()) {
            vvs.push_back(vs);
            return;
        }

        for(size_t i = start; i < s.size(); i++) {
            if(isPalindrome(s, start, i)) {
                vs.push_back(s.substr(start, i - start + 1));
                split(s, i + 1, vs);
                vs.pop_back();
            }
        }
    }


    bool isPalindrome(const string& s, size_t start, size_t end) {
        if(start == end) {
            return true;
        }

        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

int main() {
    Solution sln;

    vector<vector<string> > vvs = sln.partition("aab");
    for(size_t i = 0; i < vvs.size(); i++) {
        for(size_t j = 0; j < vvs[i].size(); j++) {
            cout << vvs[i][j] << "\t";
        }
        cout << endl;
    }

    return 0; 
}