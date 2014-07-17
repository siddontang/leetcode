#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vv;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        vector<int> v;
    
        dfs(v, 0, num, target);
        return vv;
    }

    void dfs(vector<int>& v, int level, vector<int>& num, int target) {
        if(target == 0) {
            vv.push_back(v);
            return;
        } else if(target < 0) {
            return;
        }

        for(int i = level; i < num.size(); i++) {
            if(!v.empty() && v.back() > num[i]) {
                continue;
            } 

            
            v.push_back(num[i]);
            dfs(v, i + 1, num, target - num[i]);
            v.pop_back();

            while(i < num.size() - 1 && num[i] == num[i + 1]) {
                i++;
            }
        }
    }
};

int main() {
    vector<int> n({1, 2});
    Solution sln;

    auto vv = sln.combinationSum2(n, 4);
    printVector2(vv);

    return 0;
}