#include "leetcode.h"

class Solution {
public:
    int singleNumber(int A[], int n) {
        int r = 0;
        for(int i = 0; i < 32; i++) {
            int c = 0;
            int b = 1 << i;
            for(int j = 0; j < n; j++) {
                if(A[j] & b) {
                    c++;
                }
            }

            if(c % 3) {
                r |= b;
            }
        }
        return r;
    }
};

int main() {
    int a[] = {1, 1, 1, 0};

    Solution sln;

    cout << sln.singleNumber(a, sizeof(a) / sizeof(int)) << endl;

    return 0;
}