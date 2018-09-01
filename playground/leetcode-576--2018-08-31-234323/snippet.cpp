// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
        if (N <= 0 || m <= 0 || n <= 0) return 0;
        vector<vector<int>> dp (m , vector<int>(n));
        
        for (int i=0;i<m;i++) dp[i][0] += 1;
        for (int i=0;i<m;i++) dp[i][n-1] += 1;
        for (int i=0;i<n;i++) dp[0][i] += 1;
        for (int i=0;i<n;i++) dp[m-1][i] += 1;
        int ans = dp[i][j];
        int MOD = 1e9+7;
        for (int r=1; r<N; r++) {
            vector<vector<int>> tmp(m, vector<int>(n));
            for (int j=0;j<m;j++) {
                for (int k=0;k<n;k++) {
                    tmp[j][k] = (((j>0?dp[j-1][k]:0) + (k>0?dp[j][k-1]:0)) % MOD + ((j+1<m?dp[j+1][k]:0) + (k+1<n?dp[j][k+1]:0)) % MOD) % MOD;
                }
            }
            ans = (tmp[i][j] + ans) % MOD;
            dp = tmp;
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
