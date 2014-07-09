#include "leetcode.h"

class Solution {
public:
    string intToRoman(int num) {
        string s;

        char symbol[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        int scale = 1000;

        for(int i = 6; i >= 0; i -= 2) {
            int d = num / scale;
            if(d != 0) {
                switch(d) {
                    case 1:
                    case 2:
                    case 3:
                        s.append(d, symbol[i]);
                        break;
                    case 4:
                        s.append(1, symbol[i]);
                        s.append(1, symbol[i + 1]);
                        break;
                    case 5:
                        s.append(1, symbol[i + 1]);
                        break;
                    case 6:
                    case 7:
                    case 8:
                        s.append(1, symbol[i + 1]);
                        s.append(d - 5, symbol[i]);
                        break;
                    case 9:
                        s.append(1, symbol[i]);
                        s.append(1, symbol[i + 2]);
                        break;
                }
            }

            num %= scale;
            scale /= 10;
        }

        return s;
    }
};

int main() {
    return 0;
}