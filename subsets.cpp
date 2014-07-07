#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > subsets(vector<int> &S) {
        if(S.empty()) {
            return res;
        }

        sort(S.begin(), S.end());

        res.push_back(vector<int>());

        vector<int> v;
        
        generate(0, v, S);

        return res;
    }

    void generate(int start, vector<int>& v, vector<int> &S) {
        if(start == S.size()) {
            return;
        }

        for(int i = start; i < S.size(); i++) {
            v.push_back(S[i]);

            res.push_back(v);

            generate(i + 1, v, S);

            v.pop_back();
        }
    }
};

int main() {
    Solution sln;
    vector<int> s({1, 2, 3});

    auto a = sln.subsets(s);

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}