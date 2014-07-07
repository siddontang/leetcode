#include "leetcode.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;

        v.push_back(0);

        for(int i = 0; i < n; i++) {
            int h = 1 << i;
            int len = v.size();

            for(int j = len - 1; j >= 0; j--) {
                v.push_back(h + v[j]);
            }
        }

        return v;
    }
};

int main() {
    Solution sln;

    auto a = sln.grayCode(2);

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << "\t";
    }

    cout << endl;

    return 0;
}