#include "leetcode.h"

class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            if(i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i + A[i]);
        }
        return ret;
    }
};

int main() {
    Solution sln;

    int a[] = {2, 3, 1, 1, 4};

    cout << sln.jump(a, 5) << endl;

    return 0;
}