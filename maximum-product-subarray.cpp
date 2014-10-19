#include "leetcode.h"

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 0){
            return 0;
        } else if(n == 1) {
            return A[0];
        }

        int p = A[0];
        int maxP = A[0];
        int minP = A[0];
        for(int i = 1; i < n; i++) {
            int t = maxP;
            maxP = max(max(maxP * A[i], A[i]), minP * A[i]);
            minP = min(min(t * A[i], A[i]), minP * A[i]);
            p = max(maxP, p);
        }

        return p;
    }
};

int main() {
    int a[] = {2, 3, -2, 4};
    int n = sizeof(a) / sizeof(int);

    Solution sln;
    int m = sln.maxProduct(a, n);
    cout << m << endl;

    return 0;
}