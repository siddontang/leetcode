#include "leetcode.h"

class Solution {
public:
    int singleNumber(int A[], int n) {
        int t = 0;
        
        for(int i = 0; i < n; i++) {
            t ^= A[i];
        }

        return t;
    }
};

int main() {
    int a[] = {1, 2, 1, 9, 2};
    Solution sln;

    cout << sln.singleNumber(a, 5) << endl;

    int b[] = {1, 2, 1, 7, 2};

    cout << sln.singleNumber(b, 5) << endl;

    int c[] = {1, 0, 1};

    cout << sln.singleNumber(c, 3) << endl;


    return 0;
}