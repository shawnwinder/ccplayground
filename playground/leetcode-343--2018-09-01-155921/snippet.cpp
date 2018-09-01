// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (46.72%)
 * Total Accepted:    63.8K
 * Total Submissions: 136.7K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 *
 * Example 1:
 *
 *
 *
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 x 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 x 3 x 4 = 36.
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 *
 *
 *
 */
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(60);
        for(int i=0; i<=n; i++) {
            dp[i] = i;
        }
        for(int i=4; i<=n; i++) {
            for(int j=1; j<=i/2; j++) {
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        return dp[n];
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
