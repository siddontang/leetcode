#include "leetcode.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();

        if(matrix[0][0] > target) {
            return false;
        } 

        int low = 0;
        int high = row - 1;
        int mid = row / 2;
        while(low < high) {
            if(matrix[mid][0] <= target) {
                low = mid;
            } else {
                high = mid - 1;
            }

            mid = (low + high + 1) / 2;
        }

        vector<int>& m = matrix[mid];

        low = 0;
        high = matrix[mid].size() - 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(m[mid] == target) {
                return true;
            } else if(m[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int> > a;
    a.resize(1);
    a[0] = vector<int>({1, 3});

    Solution sln;

    cout << sln.searchMatrix(a, 3) << endl;

    return 0;
}