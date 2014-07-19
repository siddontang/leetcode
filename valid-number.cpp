#include "leetcode.h"

class Solution {
public:
    bool isNumber(const char* s) 
    {
        int state = 0;
        while(*s) {
            state = getNextState(state, *s);
            if(state == -1) {
                return false;
            }
            s++;
        }

        state = getNextState(state, ' ');
        return state == 8;
    }
    
    int getNextState(int state, char c)
    {
        int transitionTable[][6] = { {0,2,1,3,-1,-1},
                                    {-1,2,-1,3,-1,-1},
                                    {8,2,-1,4,5,-1},
                                    {-1,4,-1,-1,-1,-1},
                                    {8,4,-1,-1,5,-1},
                                    {-1,7,6,-1,-1,-1},
                                    {-1,7,-1,-1,-1,-1},
                                    {8,7,-1,-1,-1,-1},
                                    {8,-1,-1,-1,-1,-1}
                                };
        return transitionTable[state][getSymbol(c)];
    }
    
    int getSymbol(char c)
    {
        switch(c)
        {
            case ' ': case '\t': return 0;
            case '0': case '1': case '2':case '3': case '4': case '5': case '6': case '7': case '8': case '9': return 1;
            case '+': case '-': return 2;
            case '.': return 3;
            case 'E': case 'e': return 4;
            default: return 5;
        }
    }
};

int main() {
    return 0;
}