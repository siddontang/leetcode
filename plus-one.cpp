#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res(digits.size(), 0);
        int sum = 0;
        int one = 1;
        for(int i =  digits.size() - 1; i >= 0; i--) {
            sum = one + digits[i];
            one = sum / 10;
            res[i] = sum % 10;
        }

        if(one > 0) {
            res.insert(res.begin(), one);
        }
        return res;
    }
};

int main() {
    return 0;
}