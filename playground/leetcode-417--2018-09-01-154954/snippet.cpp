// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (35.24%)
 * Total Accepted:    30.7K
 * Total Submissions: 87.2K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 *
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 *
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 *
 * Note:
 *
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 *
 *
 * Example:
 *
 * Given the following 5x5 matrix:
 *
 *  Pacific ~   ~   ~   ~   ~
 *       ~  1   2   2   3  (5) *
 *       ~  3   2   3  (4) (4) *
 *       ~  2   4  (5)  3   1  *
 *       ~ (6) (7)  1   4   5  *
 *       ~ (5)  1   1   2   4  *
 *          *   *   *   *   * Atlantic
 *
 * Return:
 *
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 *
 *
 */
class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty())
      return {};
    int m = matrix.size(), n = matrix[0].size();
    queue<pair<int, int>> q;
    vector<vector<char>> a(m, vector<char>(n, 0));
    auto bfs = [&](int b) {
      while (q.size()) {
        int x, y;
        tie(x, y) = q.front(), q.pop();
        if (x && ! (a[x-1][y] & b) && matrix[x][y] <= matrix[x-1][y])
          a[x-1][y] |= b, q.emplace(x-1, y);
        if (x+1 < m && ! (a[x+1][y] & b) && matrix[x][y] <= matrix[x+1][y])
          a[x+1][y] |= b, q.emplace(x+1, y);
        if (y && ! (a[x][y-1] & b) && matrix[x][y] <= matrix[x][y-1])
          a[x][y-1] |= b, q.emplace(x, y-1);
        if (y+1 < n && ! (a[x][y+1] & b) && matrix[x][y] <= matrix[x][y+1])
          a[x][y+1] |= b, q.emplace(x, y+1);
      }
    };
    REP(i, m) {
      q.emplace(i, 0);
      a[i][0] = 1;
    }
    FOR(i, 1, n) {
      q.emplace(0, i);
      a[0][i] = 1;
    }
    bfs(1);
    REP(i, m) {
      q.emplace(i, n-1);
      a[i][n-1] |= 2;
    }
    REP(i, n) {
      q.emplace(m-1, i);
      a[m-1][i] |= 2;
    }
    bfs(2);
    vector<pair<int, int>> r;
    REP(i, m)
      REP(j, n)
        if (a[i][j] == 3)
          r.emplace_back(i, j);
    return r;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
