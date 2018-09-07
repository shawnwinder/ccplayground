// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (30.68%)
 * Total Accepted:    12.2K
 * Total Submissions: 39.6K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the
 * ball, you can move the ball to adjacent cell or cross the grid boundary in
 * four directions (up, down, left, right). However, you can at most move N
 * times. Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 109 + 7.
 *
 * Example 1:
 *
 * Input:m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 * Input:m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 *
 *
 *
 *
 * Note:
 *
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 *
 *
 */
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N <= 0 || m <= 0 || n <= 0)
            return 0;
        vector<vector<long>> dp(m + 2, vector<long>(n + 2));
        for (int i = 1; i <= m; i++)
            dp[i][1] += 1;
        for (int i = 1; i <= m; i++)
            dp[i][n] += 1;
        for (int i = 1; i <= n; i++)
            dp[1][i] += 1;
        for (int i = 1; i <= n; i++)
            dp[m][i] += 1;
        int ans = dp[i+1][j+1];
        int MOD = 1e9 + 7;
        for (int r = 1; r < N; r++) {
            vector<vector<long>> tmp(m + 2, vector<long>(n + 2));
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= n; k++) {
                    tmp[j][k] = (dp[j - 1][k] + dp[j][k - 1] + dp[j + 1][k] + dp[j][k + 1]) % MOD;
                }
            }
            ans = (tmp[i+1][j+1] + ans) % MOD;
            dp = std::move(tmp);
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) {
    Solution s;
    cout << s.findPaths(2,2,2,0,0);

    return 0; }
