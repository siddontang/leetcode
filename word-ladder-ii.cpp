#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> ladders;
    unordered_map<string, unordered_set<string> > prevs;

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        deque<string> vs;

        bool found = false;

        unordered_set<string> ds;

        vs.push_back(start);
        dict.erase(start);

        for(auto it = dict.begin(); it != dict.end(); ++it) {
            prevs[*it] = unordered_set<string>();
        }

        while(!found && !vs.empty()) {
            int cnt = vs.size();
            ds.clear();
            for(int i = 0; i < cnt; i++) {
                string tmp = vs.front();
                vs.pop_front();

                string prev = tmp;

                for(int j = 0; j < prev.size(); j++) {
                    char t = tmp[j];

                    for(char c = 'a'; c <= 'z'; c++) {
                        if(t == c) {
                            continue;
                        }

                        tmp[j] = c;
                        if(tmp == end) {
                            prevs[tmp].insert(prev);
                            found = true;
                            break;
                        }

                        if(dict.find(tmp) != dict.end()) {
                            prevs[tmp].insert(prev);
                            if(ds.insert(tmp).second) {
                                vs.push_back(tmp);
                            } 
                        }
                    }

                    tmp[j] = t;
                }
            }

            if(found) {
                break;
            }

            for(auto it = ds.begin(); it != ds.end(); ++it) {
                dict.erase(*it);
            }
        } 

        vector<string> vals;
        dfs(end, end, vals);

        return ladders;
    }

    void dfs(const string& word, const string& end, vector<string>& vals) {
        auto it = prevs.find(word);
        if(it == prevs.end()) {
            vector<string> vv = vals;
            reverse(vv.begin(), vv.end());
            vv.push_back(end);

            ladders.push_back(vv);
            return;
        }
        for(auto i = it->second.begin(); i != it->second.end(); ++i) {
            vals.push_back(*i);

            dfs(*i, end, vals);

            vals.pop_back();
        }
    }
    
};

int main() {
    Solution sln;

    unordered_set<string> dict({"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"});

    auto a = sln.findLadders("nape", "mild", dict);
    cout << "---------" << endl;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << "\t";
        }

        cout << endl;
    }

    // cout << "---------" << endl;

    // sln.ladders.clear();
    // sln.prevs.clear();

    // dict = {"hot","dog","dot"};
    // a = sln.findLadders("hot", "dog", dict);
    // for(int i = 0; i < a.size(); i++) {
    //     for(int j = 0; j < a[i].size(); j++) {
    //         cout << a[i][j] << "\t";
    //     }

    //     cout << endl;
    // }

    return 0;
}