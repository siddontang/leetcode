#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > vv;

    vector<vector<int> > combine(int n, int k) {
        vector<int> v;
      
        dfs(v, 1, n, k);

        return vv;    
    }


    void dfs(vector<int>& v, int start, int n, int k) {
        if(0 == k) {
            vv.push_back(v);
            return;
        }

        for(int i = start; i <= n; i++) {
            v.push_back(i);
            dfs(v, i + 1, n, k - 1);
            v.pop_back();
        }

    }
};

int main() {
    Solution sln;

    auto a = sln.combine(4, 2);

    printVector2(a);

    return 0;
}