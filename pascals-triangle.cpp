#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vals;
        vals.resize(numRows);

        for(int i = 0; i < numRows; i++) {
            vals[i].resize(i + 1);
            vals[i][0] = 1;
            vals[i][vals[i].size() - 1] = 1;
            for(int j = 1; j < vals[i].size() - 1; j++) {
                vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j];
            }
        }

        return vals;
    }
};

int main() {
    Solution sln;

    auto a = sln.generate(5);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}