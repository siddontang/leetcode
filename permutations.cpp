#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vv;
    vector<bool> visits;
    vector<vector<int> > permute(vector<int> &num) {
        if(num.empty()) {
            return vv;
        }

        visits.resize(num.size(), false);

        vector<int> v;
        dfs(v, num, 0);

        return vv;
    }

    void dfs(vector<int>& v, vector<int>& num, int step) {
        if(step == num.size()) {
            vv.push_back(v);
            return;
        }

        for(int i = 0; i < num.size(); i++) {
            if(!visits[i]) {
                visits[i] = true;

                v.push_back(num[i]);

                dfs(v, num, step + 1);

                v.pop_back();
                visits[i] = false;
            }
        }
    }
};

int main() {
    Solution sln;

    vector<int> v({1, 2, 3});
    auto a = sln.permute(v);

    printVector2(a);

    return 0;
}