#include "leetcode.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num(n);
        int fab = 1;
        for(int i = 0; i < n; i++) {
            num[i] = i + 1;
            fab *= (i + 1);
        }   

        k--;
        string s;
        for(int i = 0; i < n; i++) {
            fab = fab / (n - i);
            int p = k / fab;
            s.push_back(num[p] + '0');
            for(int j = p; j < n - i; j++) {
                num[j] = num[j + 1];
            }

            k = k % fab;
        }
        return s;
    }
};

int main() {
    Solution sln;

    cout << sln.getPermutation(3, 4) << endl;


    return 0;
}