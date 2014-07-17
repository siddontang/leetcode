#include "leetcode.h"

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n == 0) {
            return 1;
        }

        for(int i = 0; i < n; i++) {
            while(A[i] != i + 1 && A[i] >= 1 && A[i] <= n && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(A[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    return 0;
}