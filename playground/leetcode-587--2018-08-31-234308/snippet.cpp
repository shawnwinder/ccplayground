// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [587] Erect the Fence
 *
 * https://leetcode.com/problems/erect-the-fence/description/
 *
 * algorithms
 * Hard (33.82%)
 * Total Accepted:    5.4K
 * Total Submissions: 15.9K
 * Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
 *
 * There are some trees, where each tree is represented by (x,y) coordinate in
 * a two-dimensional garden. Your job is to fence the entire garden using the
 * minimum length of rope as it is expensive. The garden is well fenced only if
 * all the trees are enclosed. Your task is to help find the coordinates of
 * trees which are exactly located on the fence perimeter.
 *
 * Example 1:
 *
 * Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 * Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [[1,2],[2,2],[4,2]]
 * Output: [[1,2],[2,2],[4,2]]
 * Explanation:
 *
 * Even you only have trees in a line, you need to use rope to enclose
 * them.
 *
 *
 *
 * Note:
 *
 * All trees should be enclosed together. You cannot cut the rope to enclose
 * trees that will separate them in more than one group.
 * All input integers will range from 0 to 100.
 * The garden has at least one tree.
 * All coordinates are distinct.
 * Input points have NO order. No order required for output.
 *
 *
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 class Solution {
 public:
   int orientation(Point p, Point q, Point r) {
     return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
   }
   vector<Point> outerTrees(vector<Point>& points) {
     auto cmp = [](Point& p, Point& q) {
       return q.x - p.x == 0 ? p.y < q.y : p.x < q.x;
     };
     sort(points.begin(), points.end(), cmp);
     vector<Point> hull;
     for (int i = 0; i < points.size(); i++) {
       while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) > 0)
         hull.pop_back();
       hull.push_back(points[i]);
     }
     hull.pop_back();
     for (int i = points.size() - 1; i >= 0; i--) {
       while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) > 0)
         hull.pop_back();
       hull.push_back(points[i]);
     }
     sort(hull.begin(), hull.end(), cmp);
     hull.erase(unique(hull.begin(), hull.end(), [](Point& p, Point& q) { return p.x == q.x && p.y == q.y;}), hull.end());
     return hull;
   }
 };



int mymain(int argc, char *argv[]) {
    return 0;
}
