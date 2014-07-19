#include "leetcode.h"

class Solution {
public:
    double findKth(int a[], int m, int b[], int n, int k) {
        if(m > n) {
            return findKth(b, n, a, m, k);
        }
        if(m == 0) {
            return b[k - 1];
        }
        if(k == 1) {
            return min(a[0], b[0]);
        }

        int pa = min(k / 2, m);
        int pb = k - pa;
        if(a[pa - 1] < b[pb - 1]) {
            return findKth(a + pa, m - pa, b, n, k - pa);
        } else if(a[pa - 1] > b[pb - 1]) {
            return findKth(a, m, b + pb, n - pb, k - pb);
        } else {
            return a[pa - 1];
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int t = m + n;
        if(t & 0x01) {
            return findKth(A, m, B, n, t / 2 + 1);
        } else {
            return (findKth(A, m, B, n, t / 2) 
                + findKth(A, m, B, n, t / 2 + 1)) / 2;
        }
    }
};

int main() {
    Solution sln;

    int a[] = {};
    int m = sizeof(a) / sizeof(int);
    int b[] = {1};
    int n = sizeof(b) / sizeof(int);

    cout << sln.findMedianSortedArrays(a, m, b, n) << endl;
    return 0;
}

