#include "leetcode.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        for(int i = len - 2; i >= 0; i--) {
            if(num[i + 1] > num[i]) {
                int j;
                for(j = len - 1; j > i; j--) {
                    if(num[j] > num[i]) {
                        break;
                    }
                }
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
    }
};

int main() {
    return 0;
}