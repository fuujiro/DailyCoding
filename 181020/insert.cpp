/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = intervals.begin();
        int cur = 0;
        while(it != intervals.end()) {
            if(it->end < newInterval.start) {
                res.push_back(*it);
                ++cur;
            } else if (it->start > newInterval.end) {
                res.push_back(*it);
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
            }
            ++it;
        }
        res.insert(res.begin() + cur, newInterval);
        return res;
    }
};
