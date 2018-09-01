// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.23%)
 * Total Accepted:    99.7K
 * Total Submissions: 654.9K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 *
 * Example 1:
 *
 *
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o
 * +------------->
 * 0  1  2  3  4
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 *
 *
 */

#ifdef CC_PLAYGROUND
struct Point {
    int x;
    int y;
    Point()
        : x(0)
        , y(0) {}
    Point(int a, int b)
        : x(a)
        , y(b) {}
};
#endif

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2)
            return points.size();
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> lines;
            int localmax = 0, overlap = 0, vertical = 0;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    overlap++;
                    continue;
                } else if (points[j].x == points[i].x)
                    vertical++;
                else {
                    int a = points[j].x - points[i].x, b = points[j].y - points[i].y;
                    int gcd = __gcd(a, b);
                    a /= gcd;
                    b /= gcd;
                    lines[make_pair(a, b)]++;
                    localmax = max(lines[make_pair(a, b)], localmax);
                }
                localmax = max(vertical, localmax);
            }
            result = max(result, localmax + overlap + 1);
        }
        return result;
    }
};

int mymain(int argc, char* argv[]) {
    Solution s;
    auto v = vector<Point>{ { 0, 0 }, { -1, -1 }, { 2, 2 } };
    cout << s.maxPoints(v);
    return 0;
}
