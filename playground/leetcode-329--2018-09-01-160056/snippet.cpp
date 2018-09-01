// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.73%)
 * Total Accepted:    .4K
 * Total Submissions: 160.1K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 *  [9,9,4],
 *  [6,6,8],
 *  [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 *  [3,4,5],
 *  [3,2,6],
 *  [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */
class Solution {
public:
    int row, col;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& m, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int res = 0;
        if (i>0 && m[i-1][j] < m[i][j]) res = max(res, dfs(m, i-1, j));
        if (j>0 && m[i][j-1] < m[i][j]) res = max(res, dfs(m, i, j-1));
        if (i+1<row && m[i+1][j] < m[i][j]) res = max(res, dfs(m, i+1, j));
        if (j+1<col && m[i][j+1] < m[i][j]) res = max(res, dfs(m, i, j+1));
        return dp[i][j] = res+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if (row == 0) return 0;
        col = matrix[0].size();
        dp.resize(row);
        for (auto& v : dp) v.assign(col, 0);
        int ans = 0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (!dp[i][j]) ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
