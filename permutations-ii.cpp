#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vv;
    vector<bool> visits;
    vector<vector<int> > permuteUnique(vector<int> &num) {
         if(num.empty()) {
            return vv;
        }

        visits.resize(num.size(), false);

        sort(num.begin(), num.end());

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
                if(i > 0 && num[i] == num[i - 1] && visits[i - 1] == 0) {
                    continue;
                }

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

    vector<int> num({1, 1, 2});
    auto vv = sln.permuteUnique(num);

    printVector2(vv);

    return 0;
}