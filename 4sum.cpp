#include "leetcode.h"

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > vv;

        sort(num.begin(), num.end());

        int len = num.size();

        for(int i = 0; i < len - 3; i++) {
            if(i > 0 && num[i - 1] == num[i]) {
                continue;
            }

            for(int j = i + 1; j < len - 2; j++) {
                if(j > i + 1 && num[j - 1] == num[j]) {
                    continue;
                }  

                int start = j + 1;
                int end = len - 1;
                int target2 = target - num[i] - num[j];
                while(start < end) {
                    int sum = num[start] + num[end];
                    if(sum == target2) {
                        vv.push_back(vector<int>({num[i], num[j], num[start], num[end]}));
                        start++;
                        end--;
                
                        while(start < end && num[start] == num[start - 1]) {
                            start++;
                        }

                        while(start < end && num[end + 1] == num[end]) {
                            end--;
                        }
                    } else if(sum < target2) {
                        start++;
                    } else {
                        end--;
                    }                 
                }
            }
        }

        return vv;
    }
};

int main() {
    Solution sln;

    vector<int> num({1,0,-1,0,-2,2});
    auto vv = sln.fourSum(num, 0);

    printVector2(vv);
    return 0;
}