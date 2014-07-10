#include "leetcode.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
        return divide(A, 0, n - 1, INT_MIN);
    }

    int divide(int A[], int left, int right, int tmax) {
        if(left > right) {
            return INT_MIN;
        }

        int mid = (left + right) / 2;
        int lmax = divide(A, left, mid - 1, tmax);
        int rmax = divide(A, mid + 1, right, tmax);

        tmax = max(tmax, lmax);
        tmax = max(tmax, rmax);

        int sum = 0;
        int mlmax = 0;
        for(int i = mid - 1; i >= left; i--) {
            sum += A[i];
            mlmax = max(mlmax, sum);
        }

        sum = 0;
        int mrmax = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += A[i];
            mrmax = max(mrmax, sum);
        }

        tmax = max(tmax, A[mid] + mlmax + mrmax);
        return tmax;
    }
};

int main() {
    Solution sln;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(a) / sizeof(int);

    cout << sln.maxSubArray(a, n) << endl;

    return 0;
}