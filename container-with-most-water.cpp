#include "leetcode.h"

class Solution {
public:
    int maxArea(vector<int> &height) {
        int s = 0;
        int e = height.size() - 1;
        int a = numeric_limits<int>::min();

        while(s < e) {
            int c = min(height[s], height[e]) * (e - s);
            a = max(a, c);

            if(height[s] <= height[e]) {
                s++;
            } else {
                e--;
            }
        }

        return a;
    }
};

int main() {
    return 0;
}