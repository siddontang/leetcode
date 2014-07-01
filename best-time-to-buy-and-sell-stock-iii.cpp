#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = (int)prices.size();
        if(len <= 1) {
            return 0;
        }

        vector<int> profits;
        profits.resize(len);

        int minP = prices[0];
        int sum = numeric_limits<int>::min();
        for(int i = 1; i < len; i++) {
            minP = min(minP, prices[i - 1]);
            profits[i] = max(sum, prices[i] - minP);

            sum = profits[i];
        }

        int maxP = prices[len - 1];
        int sum2 = numeric_limits<int>::min();

        for(int i = len - 2; i >= 0; i--) {
            maxP = max(maxP, prices[i + 1]);
            sum2 = max(sum2, maxP - prices[i]);
        
            if(sum2 > 0) {
                profits[i] = profits[i] + sum2;
                sum = max(sum, profits[i]);
            }
        }

 
        return sum > 0 ? sum : 0;
    }
};

int main() {
    Solution sln;
    vector<int> prices({1, 2});

    cout << sln.maxProfit(prices) << endl;

    prices = {2,1,2,0,1};

    cout << sln.maxProfit(prices) << endl;

    prices = {3,2,6,5,0,3};

    cout << sln.maxProfit(prices) << endl;

    return 0;
}