#include "leetcode.h"

class Solution {
public:
    string minWindow(string S, string T) {
        if(S.empty() || S.size() < T.size()) {
            return "";
        }

        vector<int> appearCnt(256, 0);
        vector<int> expectCnt(256, 0);
        for(int i = 0; i < T.size(); i++) {
            expectCnt[T[i]]++;
        }

        int minV = INT_MAX;
        int start = 0;
        int end = 0;
        int cnt = 0;

        for(int i = 0; i < S.size(); i++) {
            char c = S[i];
            if(expectCnt[c] > 0) {
                appearCnt[c]++;
                if(appearCnt[c] <= expectCnt[c]) {
                    cnt++;
                }
            }

            if(cnt == T.size()) {
                while(appearCnt[S[end]] > expectCnt[S[end]] || 
                    expectCnt[S[end]] == 0) {
                    appearCnt[S[end]]--;
                    end++;
                }

                if(minV > (i - end + 1)) {
                    minV = i - end + 1;
                    start = end;
                }
            }
        }

        if(minV == INT_MAX) {
            return "";
        }

        return S.substr(start, minV);
    }
};

int main() {
    Solution sln;

    cout << sln.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}