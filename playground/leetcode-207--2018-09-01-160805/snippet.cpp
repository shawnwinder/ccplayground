// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (34.66%)
 * Total Accepted:    143.7K
 * Total Submissions: 414.6K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */
class Solution {
public:
  bool canFinish(int n, vector<pair<int, int>> &a) {
    vector<int> d(n, 0);
    vector<vector<int>> e(n);
    int top = -1, num = 0;
    for (auto x: a) {
      d[x.second]++;
      e[x.first].push_back(x.second);
    }
    REP(i, n)
      if (! d[i])
        d[i] = top, top = i;
    while (top != -1) {
      int x = top;
      top = d[top];
      num++;
      for (auto y: e[x])
        if (! --d[y])
          d[y] = top, top = y;
    }
    return num == n;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
