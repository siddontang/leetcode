#include "leetcode.h"

class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0) {
            return 0;
        }
        int maxL[n];
        int maxR[n];
        maxL[0] = A[0];
        for(int i = 1; i < n; i++) {
            maxL[i] = max(maxL[i - 1], A[i]);
        }

        maxR[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxR[i] = max(maxR[i + 1], A[i]);
        }

        int sum = 0;
        for(int i = 1; i < n - 1; i++) {
            sum += min(maxL[i], maxR[i]) - A[i];
        }

        return sum;
    }
};

int main() {
    Solution sln;
    int a[] = {5,5,1,7,1,1,5,2,7,6};
    int n = sizeof(a) / sizeof(int);

    cout << sln.trap(a, n) << endl;
    return 0;
}