#include "leetcode.h"

class Solution {
public:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> v;
        v.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            Interval& n1 = v.back();
            Interval& n2 = intervals[i];

            if((n1.start <= n2.start && n2.start <= n1.end) ||
               (n2.start <= n1.start && n1.start <= n2.end)) {
                v.pop_back();
                n1.start = min(n1.start, n2.start);
                n1.end = max(n1.end, n2.end);
                v.push_back(n1);
            } else {
                v.push_back(n2);
            }

        }

        return v;
    }
};

int main() {
    return 0;
}