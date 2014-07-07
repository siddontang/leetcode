#include "leetcode.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) {
            return 0;
        }

        int index = 0;
        for(int i = 1; i < n; i++) {
            if(A[index] != A[i]) {
                A[++index] = A[i];
            }
        }
        return index + 1;
    }
};

int main() {
    Solution sln;

    int a[] = {1, 1, 2};

    cout << sln.removeDuplicates(a, 3) << endl;

    return 0;
}