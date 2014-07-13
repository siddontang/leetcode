#include "leetcode.h"

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int minV = numeric_limits<int>::max();

        int minS = 0;
        int len = num.size();

        for(int i = 0; i < len; i++) {
            int start = i + 1;
            int end = len - 1;
            while(start < end) {
                int sum = num[i] + num[start] + num[end];
                if(sum == target) {
                    return target;
                } else if(sum < target) {
                    if(target - sum < minV) {
                        minV = target - sum;
                        minS = sum;
                    }
                    start++;
                } else {
                    if(sum - target < minV) {
                        minV = sum - target;
                        minS = sum;
                    }
                    end--;
                }
            }
            while(i < len - 1 && num[i + 1] == num[i]) {
                i++;
            }
        }

        return minS;
    }
};

int main() {
    Solution sln;

    vector<int> nums({0, 0, 0});

    cout << sln.threeSumClosest(nums, 1) << endl;

    return 0;
}