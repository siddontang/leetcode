#include "leetcode.h"

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> h;
        unordered_set<int>::iterator it;
        int l = (int)num.size();
        for(int i = 0; i < l; i++) {
            h.insert(num[i]);
        }

        int n = 0;
        int c = 0;
        int j = 0;
        for(int i = 0; i < l; i++) {
            it = h.find(num[i]);
            if(it != h.end()) {
                c = 1;
                h.erase(it);
                j = num[i];
                while(true) {
                    ++j;
                    it = h.find(j);
                    if(it != h.end()) {
                        h.erase(it);
                        c++;
                    } else {
                        break;
                    }
                }
                j = num[i];
                while(true) {
                    --j;
                    it = h.find(j);
                    if(it != h.end()) {
                        h.erase(it);
                        c++;
                    } else {
                        break;
                    }
                }

                if(c > n) {
                    n = c;
                }
            }
        }

        return n;
    }
};

int main() {
    Solution sln;
    vector<int> num;

    num.push_back(100);
    num.push_back(4);
    num.push_back(200);
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);

    cout << sln.longestConsecutive(num) << endl;

    return 0;
}