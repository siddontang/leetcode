#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > vv;
        int start, end, i;

        sort(num.begin(), num.end());

        for(int i = 0; i < num.size(); i++) {
            int target = 0 - num[i];
            int start = i + 1;
            int end = num.size() - 1;

            while(start < end) {
                if(num[start] + num[end] == target) {
                    vv.push_back(vector<int>({num[i], num[start], num[end]}));
                    start++;
                    end--;
                
                    while(start < end && num[start] == num[start - 1]) {
                        start++;
                    }

                    while(start < end && num[end + 1] == num[end]) {
                        end--;
                    }
                } else if(num[start] + num[end] < target) {
                    start++;
                } else {
                    end--;
                }
            }

            while(i < num.size() - 1 && num[i + 1] == num[i]) {
                i++;
            }
        }

        return vv;
    }
};

int main() {
    Solution sln;

    vector<int> nums({-1, 0, 1, 2, -1, -4});
    auto vv = sln.threeSum(nums);

    printVector2(vv);

    return 0;
}