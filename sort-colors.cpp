#include "leetcode.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        if(n == 0) {
            return;
        }

        int red = 0;
        int blue = n - 1;
        int i = 0;
        while(i < blue + 1) {
            if(A[i] == 0) {
                swap(A[i], A[red]);
                red++;
            } else if(A[i] == 2) {
                swap(A[i], A[blue]);
                blue--;
                continue;
            }
            i++;
        }
    }
};

int main() {
    int a[] = {2, 1, 0, 1, 1, 2, 2, 0, 0};

    Solution sln;
    sln.sortColors(a, sizeof(a) / sizeof(int));

    for(int i = 0; i < sizeof(a) / sizeof(int); i++) {
        cout << a[i] << "\t";
    }

    cout << endl;

    return 0;
}