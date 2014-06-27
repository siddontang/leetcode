#include "leetcode.h"

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candys;
        candys.resize(ratings.size(), 1);
        for(int i = 1; i < (int)ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) {
                candys[i] = candys[i - 1] + 1;
            }
        }

        for(int i = (int)ratings.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1] && candys[i] <= candys[i + 1]) {
                candys[i] = candys[i + 1] + 1;
            }
        }

        int n = 0;
        for(int i = 0; i < (int)candys.size(); i++) {
            n += candys[i];
        }

        return n;
    }
};

int main() {
    Solution sln;

    vector<int> ratings;

    ratings.push_back(0);
  

    cout << sln.candy(ratings) << endl;

    return 0;
}