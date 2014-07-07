#include "leetcode.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) {
            return 0;
        }

        int index = 0;
        int num = 0;
        for(int i = 1; i < n; i++) {
            if(A[index] == A[i]) {
                num++;
                if(num < 2) {
                    A[++index] = A[i];
                }
            } else {
                A[++index] = A[i];
                num = 0;
            }
        }
        return index + 1;
    }
};

int main() {
    Solution sln;

    int a[] = {1, 1, 1, 2, 2, 3};

    cout << sln.removeDuplicates(a, 6) << endl;

    return 0;
}