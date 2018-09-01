// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (32.86%)
 * Total Accepted:    230.7K
 * Total Submissions: 702K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> r;
        sort(intervals.begin(), intervals.end(),
            [](const Interval& x, const Interval& y) { return x.start < y.start; });
        for (auto& i : intervals)
            if (r.empty() || r.back().end < i.start)
                r.push_back(i);
            else {
                Interval& x = r.back();
                x.start = min(x.start, i.start);
                x.end = max(x.end, i.end);
            }
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
