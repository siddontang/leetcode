#include "leetcode.h"

class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();

        if(size == 0) {
            return 0;
        } else if(size == 1) {
            return num[0];
        } else if(size == 2) {
            return min(num[0], num[1]);
        }

        int start = 0;
        int stop = size - 1;

        while(start < stop - 1) {
            if(num[start] < num[stop]) {
                return num[start];
            }

            int mid = start + (stop - start) / 2;
            if(num[mid] > num[start]) {
                start = mid;
            } else if(num[mid] < num[start]) {
                stop = mid;
            } else {
                start++;
            }
        }

        return min(num[start], num[stop]);
    }
};

int main() {
    Solution sln;

    vector<int> num{1,1};

    cout << sln.findMin(num) << endl;

    num = vector<int>{3,3,1,3};
    cout << sln.findMin(num) << endl;

    num = vector<int>{3,1,3};
    cout << sln.findMin(num) << endl;

    num = vector<int>{3,5,1};
    cout << sln.findMin(num) << endl;

    return 0;
}