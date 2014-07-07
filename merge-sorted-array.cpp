#include "leetcode.h"

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m + n - 1;
        int j = m - 1;
        int k = n - 1;

        while(i >= 0) {
            if(j >= 0 && k >= 0) {
                if(A[j] > B[k]) {
                    A[i] = A[j];
                    j--;
                } else {
                    A[i] = B[k];
                    k--;
                }                
            } else if(j >= 0) {
                A[i] = A[j];
                j--;
            } else if(k >= 0) {
                A[i] = B[k];
                k--;
            }
            i--;
        }
    }
};

int main() {
    return 0;
}