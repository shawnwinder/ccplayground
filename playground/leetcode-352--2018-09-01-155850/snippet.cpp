// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 * [352] Data Stream as Disjoint Intervals
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (41.52%)
 * Total Accepted:    18.9K
 * Total Submissions: 45.5K
 * Testcase Example:
 * '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an, ...,
 * summarize the numbers seen so far as a list of disjoint intervals.
 *
 * For example, suppose the integers from the data stream are 1, 3, 7, 2, 6,
 * ..., then the summary will be:
 *
 *
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 *
 *
 * Follow up:
 * What if there are lots of merges and the number of disjoint intervals are
 * small compared to the data stream's size?
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

class SummaryRanges {
    set<int> s;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) { s.insert(val); }

    vector<Interval> getIntervals() {
        vector<Interval> r;
        for (auto i = s.begin(); i != s.end();) {
            Interval x(*i, *i);
            auto j = i++;
            while (i != s.end() && *j + 1 == *i) {
                x.end = *i++;
                ++j;
            }
            r.push_back(x);
        }
        return r;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int mymain(int argc, char* argv[]) { return 0; }
