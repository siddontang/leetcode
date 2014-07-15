#include "leetcode.h"

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if(n == 0) {
            return vector<int>({-1, -1});
        }

        vector<int> v;
        int low = 0;
        int high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(low < n && A[low] == target) {
            v.push_back(low);
        } else {
            return vector<int>({-1, -1});
        }

        low = low;
        high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        
        v.push_back(high);
        return v;
    }
};

int main() {
    int a[] = {7, 8, 8};
    int n = sizeof(a) / sizeof(int);

    Solution sln;
    auto v = sln.searchRange(a, n, 8);

    printVector(v);

    return 0;
}