#include "leetcode.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < numbers.size(); i++) {
            m[numbers[i]] = i;
        }

        int index1, index2;

        for(int i = 0; i < numbers.size(); i++) {
            auto it = m.find(target - numbers[i]);
            if(it != m.end() && it->second != i) {
                index1 = min(i, it->second);
                index2 = max(i, it->second);
                break;
            }
        }

        return vector<int>({index1 + 1, index2 + 1});
    }
};

int main() {
    Solution sln;

    vector<int> n({2, 7, 11, 15});

    auto v = sln.twoSum(n, 9);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
    return 0;
}