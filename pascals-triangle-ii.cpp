#include "leetcode.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vals;
        vector<int> last;

        last.resize(rowIndex + 1);
        vals.resize(rowIndex + 1);

        last[0] = 1;

        for(int i = 0; i < rowIndex + 1; i++) {
            vals[0] = 1;
            vals[i] = 1;

            for(int j = 1; j < i; j++) {
                vals[j] = last[j -1] + last[j];
            }

            vals.swap(last);
        }

        return last;
    }
};

int main() {
    Solution sln;

    auto a = sln.getRow(3);
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << "\t";
    }

    cout << endl;
    return 0;
}