#include "leetcode.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        vector<int> s;
        height.push_back(0);

        int sum = 0;
        int i = 0;
        while(i < height.size()) {
            if(s.empty() || height[i] > height[s.back()]) {
                s.push_back(i);
                i++;
            } else {
                int t = s.back();
                s.pop_back();
                sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
            }
        }

        return sum;
    }
};

int main() {
    vector<int> height({1, 1});

    Solution sln;
    cout << sln.largestRectangleArea(height) << endl;

    return 0;
}