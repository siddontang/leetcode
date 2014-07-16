#include "leetcode.h"

class Solution {
public:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto it = intervals.begin();
        auto it_prev = it;
        while(it != intervals.end()) {
            if(newInterval.end < it->start) {
                if(it != it_prev) {
                    it = intervals.erase(it_prev, it);
                }
                intervals.insert(it, newInterval);
                return intervals;
            } else if(newInterval.start > it->end) {
                ++it;
                ++it_prev;
                continue;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                ++it;
            }
        }

        if(it != it_prev) {
            it = intervals.erase(it_prev, it);
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};

int main() {
    return 0;
}