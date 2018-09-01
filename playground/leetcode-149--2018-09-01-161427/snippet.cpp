// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
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
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
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
  int maxPoints(const vector<Point>& points) {
    int max = 1;
    if (points.size() <= 2) return points.size();
    for (int i=0;i<points.size();i++) {
      unordered_map<Fraction, int> cnt;
      int dup = 0;
      int vert = 1;
      int local = 1;
      for (int j=i+1;j<points.size();j++) {
        if (points[i].x == points[j].x) {
          if (points[i].y == points[j].y) {
            dup ++;
          } else {
            vert ++;
          }
        } else {
          auto& num = cnt[{points[j].y - points[i].y , points[j].x - points[i].x}];
          num ++;
          if (local < num + 1) local = num + 1;
        }
      }
      if (max < local + dup) max = local + dup;
      if (max < dup + vert) max = dup + vert;
    }
    return max;
  }
};

#ifdef AMOS
int main() {
  ios::sync_with_stdio(false);
  Solution s;
  cout << s.maxPoints(vector<Point>{{0,0}, {-1,-1}, {2,2}});
}
#endif


int mymain(int argc, char *argv[]) {
    return 0;
}
