#include "leetcode.h"

class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size() - 1);
    }

    int findMin(vector<int> &num, int start, int stop) {
        if(start == stop) {
            return num[start];
        }
        
        if(num[start] < num[stop]) {
            return num[start];
        }

        int mid = start + (stop - start) / 2;
        if(num[mid] > num[stop]) {
            return findMin(num, mid + 1, stop);
        }

        return findMin(num, start, mid);
    }
};

int main() {
    Solution sln;

    vector<int> v{1,2,3,4,5,6,7};
    int m = sln.findMin(v);

    cout << m << endl;

    v = vector<int>{4,5,6,7,0,1,2};
    m = sln.findMin(v);

    cout << m << endl;
    return 0;
}