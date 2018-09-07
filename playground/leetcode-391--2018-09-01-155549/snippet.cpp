// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 * [391] Perfect Rectangle
 *
 * https://leetcode.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (27.63%)
 * Total Accepted:    15.6K
 * Total Submissions: 56.4K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together
 * form an exact cover of a rectangular region.
 *
 *
 *
 * Each rectangle is represented as a bottom-left point and a top-right point.
 * For example, a unit square is represented as [1,1,2,2]. (coordinate of
 * bottom-left point is (1, 1) and top-right point is (2, 2)).
 *
 *
 *
 * Example 1:
 *
 * rectangles = [
 *  [1,1,3,3],
 *  [3,1,4,2],
 *  [3,2,4,4],
 *  [1,3,2,4],
 *  [2,3,3,4]
 * ]
 *
 * Return true. All 5 rectangles together form an exact cover of a rectangular
 * region.
 *
 *
 *
 *
 *
 *
 * Example 2:
 *
 * rectangles = [
 *  [1,1,2,3],
 *  [1,3,2,4],
 *  [3,1,4,2],
 *  [3,2,4,4]
 * ]
 *
 * Return false. Because there is a gap between the two rectangular
 * regions.
 *
 *
 *
 *
 *
 *
 * Example 3:
 *
 * rectangles = [
 *  [1,1,3,3],
 *  [3,1,4,2],
 *  [1,3,2,4],
 *  [3,2,4,4]
 * ]
 *
 * Return false. Because there is a gap in the top center.
 *
 *
 *
 *
 *
 *
 * Example 4:
 *
 * rectangles = [
 *  [1,1,3,3],
 *  [3,1,4,2],
 *  [1,3,2,4],
 *  [2,2,4,4]
 * ]
 *
 * Return false. Because two of the rectangles overlap with each other.
 *
 *
 *
 *
 */

class Solution {
public:
    // sweep line
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long area = 0, x0 = INT_MAX, x1 = INT_MIN, y0 = INT_MAX, y1 = INT_MIN;
        vector<pair<int, pair<int, int>>> b;
        set<pair<int, int>> active;
        for (auto& a : rectangles) {
            x0 = min(x0, long(a[0]));
            y0 = min(y0, long(a[1]));
            x1 = max(x1, long(a[2]));
            y1 = max(y1, long(a[3]));
            area += (long(a[2]) - a[0]) * (long(a[3]) - a[1]);
            b.emplace_back(a[0] * 2 + 1, make_pair(a[1], a[3]));
            b.emplace_back(a[2] * 2, make_pair(a[1], a[3]));
        }
        sort(b.begin(), b.end());
        for (auto& a : b)
            if (a.first % 2) {
                auto it = active.lower_bound(a.second);
                if ((it != active.begin() && a.second.first < prev(it)->second)
                    || (it != active.end() && it->first < a.second.second))
                    return false;
                active.insert(it, a.second);
            } else
                active.erase(a.second);
        return area == (x1 - x0) * (y1 - y0);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
