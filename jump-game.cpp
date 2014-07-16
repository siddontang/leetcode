#include "leetcode.h"

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0) {
            return true;
        }

        int v = A[0];
        
        for(int i = 1; i < n; i++) {
            v--;
            if(v < 0) {
                return false;
            }

            if(v < A[i]) {
                v = A[i];
            }
        }
        return true;
    }
};

int main() {
    Solution sln;
    
    int a[] = {2, 3, 1, 1, 4};
    cout << sln.canJump(a, 5) << endl;

    int b[] = {3, 2, 1, 0, 4};
    cout << sln.canJump(b, 5) << endl;


    return 0;
}