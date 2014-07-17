#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vv;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(v, candidates, target);
        return vv;
    }

    void dfs(vector<int>& v, vector<int> &candidates, int target) {
        if(target == 0) {
            vv.push_back(v);
            return;
        } else if(target < 0) {
            return;
        }

        for(int i = 0; i < candidates.size(); i++) {
            if(!v.empty() && v.back() > candidates[i]) {
                continue;
            }
            v.push_back(candidates[i]);
            dfs(v, candidates, target - candidates[i]);
            v.pop_back();
        }
    }
};

int main() {
    Solution sln;

    vector<int> c({2, 3, 6, 7});

    auto vv = sln.combinationSum(c, 7);

    printVector2(vv);

    return 0;
}