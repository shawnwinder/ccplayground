// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [630] Course Schedule III
 *
 * https://leetcode.com/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (29.64%)
 * Total Accepted:    7.4K
 * Total Submissions: 25K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 *
 * There are n different online courses numbered from 1 to n. Each course has
 * some duration(course length)  t and closed on dth day. A course should be
 * taken continuously for t days and must be finished before or on the dth day.
 * You will start at the 1st day.
 *
 *
 *
 * Given n online courses represented by pairs (t,d), your task is to find the
 * maximal number of courses that can be taken.
 *
 *
 *
 * Example:
 *
 * Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 * Output: 3
 * Explanation:
 * There're totally 4 courses, but you can take 3 courses at most:
 * First, take the 1st course, it costs 100 days so you will finish it on the
 * 100th day, and ready to take the next course on the 101st day.
 * Second, take the 3rd course, it costs 1000 days so you will finish it on the
 * 1100th day, and ready to take the next course on the 1101st day.
 * Third, take the 2nd course, it costs 200 days so you will finish it on the
 * 1300th day.
 * The 4th course cannot be taken now, since you will finish it on the 3300th
 * day, which exceeds the closed date.
 *
 *
 *
 *
 * Note:
 *
 * The integer 1
 * You can't take two courses simultaneously.
 *
 *
 */
class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    auto cmp = [](const vector<int>& l, const vector<int>& r) {
      return l[1] < r[1];
    };
    sort(courses.begin(), courses.end(), cmp);
    vector<int> res(courses.back()[1] + 1, 0);
    priority_queue<int> pq;
    int ctime = 0;
    for (auto& c : courses) {
      if (ctime + c[0] > c[1]) {
        if (!pq.empty() && pq.top() > c[0]) {
          int delta = pq.top() - c[0];
          pq.pop();
          pq.push(c[0]);
          ctime -= delta;
        }
      } else {
        ctime += c[0];
        pq.push(c[0]);
      }
    }
    return pq.size();
  }
};



int mymain(int argc, char *argv[]) {
    return 0;
}
