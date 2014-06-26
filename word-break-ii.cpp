#include "leetcode.h"

class Solution {
public:
    vector<string> wordBreak(string s, set<string> &dict) {
        vector<string> vals;

        int len = (int)s.size();
        vector<vector<char> > words;
        words.resize(len);
        for(int i = 0; i < len; i++) {
            words[i].resize(len + 1, 0);
        }

        for(int i = 1; i <= len; i++) {
            for(int j = 0; j < len; j++) {
                if(dict.find(s.substr(j, i)) != dict.end()) {
                    words[j][i] = 1;
                    continue;
                }
                for(int k = 1; k < i; k++) {
                    if(words[j][k] && words[j + k][i - k]) {
                        words[j][i] = 2;
                        break;
                    }
                }
            }
        }

        if(words[0][len] == 0) {
            return vals;
        }

        string val;

        dfs(s, 0, val, words, vals);
        return vals;
    }

    void dfs(const string& s, int start, string& val, vector<vector<char> >&words, vector<string>& vals) {
        int len = (int)s.size();
        if(start == len) {
            vals.push_back(val);
            return;
        }

        for(int i = 1; i <= len - start;i++) {
            if(words[start][i] == 1) {
                int oldLen = (int)val.size();
                if(oldLen != 0) {
                    val.append(" ");
                }
                val.append(s.substr(start, i));

                dfs(s, start + i, val, words, vals);
                val.erase(oldLen, string::npos);
            }
        }
    }
};

int main() {
    string s = "catsanddog";
    set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");

    Solution sln;

    vector<string> a = sln.wordBreak(s, dict);
    for(int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << endl;
    }

    return 0;
}