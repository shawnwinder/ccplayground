// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (29.60%)
 * Total Accepted:    139.5K
 * Total Submissions: 471.4K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 */

#ifdef CC_PLAYGROUND
struct Interval {
    int start;
    int end;
    Interval()
        : start(0)
        , end(0) {}
    Interval(int s, int e)
        : start(s)
        , end(e) {}
};
#endif

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto cmp = [](const Interval& a, const Interval& b) { return a.end < b.end; };
        auto cmp2 = [](const Interval& a, const int b) { return a.end < b; };
        sort(intervals.begin(), intervals.end(), cmp);
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval.start, cmp2);
        if (it == intervals.end() || it->start > newInterval.end)
            intervals.insert(it, newInterval);
        else {
            int l = min(it->start, newInterval.start);
            int r = max(it->end, newInterval.end);
            while (it != intervals.end() && it->end < r)
                it = intervals.erase(it);
            if (it != intervals.end() && it->start <= r)
                r = it->end, it = intervals.erase(it);
            intervals.insert(it, { l, r });
        }
        return intervals;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
