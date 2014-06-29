#include "leetcode.h"

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        deque<string> vs;
        vs.push_back(start);

        int n = 1;
            
        while(!vs.empty()) {
            size_t count = vs.size();
            for(size_t ct = 0; ct < count; ct++) {
                string tmp = vs.front();
                vs.pop_front();

                if(!tmp.empty()) {
                    for(size_t i = 0; i < tmp.size(); i++) 
                    {
                        char t = tmp[i];
                        for(char c = 'a'; c <= 'z'; c++) {
                            if(c == t) {
                                continue;
                            }

                            tmp[i] = c;
                            if(tmp == end) {
                                return n + 1;
                            }

                            if(dict.find(tmp) != dict.end()) {
                                vs.push_back(tmp);
                                dict.erase(tmp);
                            }
                        }               

                        tmp[i] = t; 
                    }
                }   
            }
            n++;
        }

        return 0;
    }
};

int main() {
    Solution sln;
    unordered_set<string> dict({"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"});
    string start = "qa";
    string end = "sq";

    cout << sln.ladderLength(start, end, dict) << endl;

    return 0;
}