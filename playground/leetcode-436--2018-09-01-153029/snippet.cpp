// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
 * [436] Find Right Interval
 *
 * https://leetcode.com/problems/find-right-interval/description/
 *
 * algorithms
 * Medium (41.77%)
 * Total Accepted:    20.8K
 * Total Submissions: 49.8K
 * Testcase Example:  '[[1,2]]'
 *
 *
 * Given a set of intervals, for each of the interval i, check if there exists
 * an interval j whose start point is bigger than or equal to the end point of
 * the interval i, which can be called that j is on the "right" of i.
 *
 *
 *
 * For any interval i, you need to store the minimum interval j's index, which
 * means that the interval j has the minimum start point to build the "right"
 * relationship for interval i. If the interval j doesn't exist, store -1 for
 * the interval i. Finally, you need output the stored value of each interval
 * as an array.
 *
 *
 * Note:
 *
 * You may assume the interval's end point is always bigger than its start
 * point.
 * You may assume none of these intervals have the same start point.
 *
 *
 *
 * Example 1:
 *
 * Input: [ [1,2] ]
 *
 * Output: [-1]
 *
 * Explanation: There is only one interval in the collection, so it outputs
 * -1.
 *
 *
 *
 * Example 2:
 *
 * Input: [ [3,4], [2,3], [1,2] ]
 *
 * Output: [-1, 0, 1]
 *
 * Explanation: There is no satisfied "right" interval for [3,4].
 * For [2,3], the interval [3,4] has minimum-"right" start point;
 * For [1,2], the interval [2,3] has minimum-"right" start point.
 *
 *
 *
 * Example 3:
 *
 * Input: [ [1,4], [2,3], [3,4] ]
 *
 * Output: [-1, 2, -1]
 *
 * Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
 * For [2,3], the interval [3,4] has minimum-"right" start point.
 *
 *
 */

#ifdef CC_PLAYGROUND
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
#endif

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        using pp = pair<int, int>;
        vector<pp> d;
        int idx = 0;
        for (auto& i : intervals) {
            d.push_back(pp(i.start, idx++));
        }
        sort(d.begin(), d.end());
        vector<int> ret;
        for (auto& i : intervals) {
            auto x = lower_bound(d.begin(), d.end(), pp(i.end, INT_MIN));
            if (x == d.end())
                ret.push_back(-1);
            else
                ret.push_back(x->second);
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
