#include "leetcode.h"

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> nums;

        for(int i = 0; i < int(tokens.size()); i++) {
            if(isOperator(tokens[i])) {
                calc(nums, tokens[i][0]);
            } else {
                int n = atoi(tokens[i].c_str());
                nums.push_back(n);
            }
        }

        return nums[0];
    }

    bool isOperator(const string& str) {
        if(str.size() != 1) {
            return false;
        }

        switch(str[0]) {
            case '+':
                return true;
            case '-':
                return true;
            case '*':
                return true;
            case '/':
                return true;
            default:
                return false;
        }
    }

    void calc(vector<int>& nums, char opt) {
        int a2 = nums.back();
        nums.pop_back();
        int a1 = nums.back();
        nums.pop_back();

        int result = 0;

        switch(opt) {
            case '+':
                result = a1 + a2;
                break;
            case '-':
                result = a1 - a2;
                break;
            case '*':
                result = a1 * a2;
                break;
            case '/':            
                result = a1 / a2;
                break;
        }
        nums.push_back(result);
    }
};

int main() {
    Solution sln;

    string ay1[5] = {"2", "1", "+", "3", "*"};
    vector<string> s1(ay1, ay1 + 5);

    string ay2[5] = {"4", "13", "5", "/", "+"};
    vector<string> s2(ay2, ay2 + 5);

    cout << sln.evalRPN(s1) << endl;
    cout << sln.evalRPN(s2) << endl;

    return 0;
}