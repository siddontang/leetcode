#include "leetcode.h"

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = 0;
        for(i = 0; i < n; i++) {
            if(A[i] == elem) {
                continue;
            }

            A[j] = A[i];
            j++;
        }

        return j;
    }
};

int main() {
    Solution sln;

    int a[] = {4, 4};
    int n = sizeof(a) / sizeof(int);

    cout << sln.removeElement(a, n, 3) << endl;

    return 0;
}