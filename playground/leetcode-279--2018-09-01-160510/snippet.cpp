// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (38.61%)
 * Total Accepted:    127.2K
 * Total Submissions: 329.3K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *
 */
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{ 0 };
        int m = dp.size();
        dp.resize(max(m, n + 1), INT_MAX);
        for (int i = 1, i2; (i2 = i * i) <= n; ++i)
            for (int j = max(m, i2); j <= n; ++j)
                if (dp[j] > dp[j - i2] + 1)
                    dp[j] = dp[j - i2] + 1;
        return dp[n];
    }
};

int mymain(int argc, char* argv[]) { return 0; }
