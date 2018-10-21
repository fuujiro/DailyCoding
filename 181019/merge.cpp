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
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> res;
        vector<int> starts, ends;
        for(int i = 0; i < n; ++i) {
            starts.push_back(intervals[i].start);
            ends.push_back(intervals[i].end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for(int i = 0, j = 0; i < n; ++i) {
            if(i == n - 1 || starts[i + 1] > ends[i]) {
                res.push_back(Interval(starts[j], ends[i]));
                j = i + 1;
            }
        }
        return res;
    }
};
