#include "leetcode.h"

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0;
        int h = n - 1;

        while(l <= h) {
            int mid = (l + h) / 2;
            if(A[mid] == target) {
                return mid;
            } 

            if(A[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return l;
    }
};

int main() {
    Solution  sln;
    int a[] = {1, 3, 5, 6};
    int n = sizeof(a) / sizeof(int);

    cout << sln.searchInsert(a, n, 5) << endl;
    cout << sln.searchInsert(a, n, 2) << endl;
    cout << sln.searchInsert(a, n, 7) << endl;
    cout << sln.searchInsert(a, n, 0) << endl;



    return 0;
}