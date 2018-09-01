// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.48%)
 * Total Accepted:    237.1K
 * Total Submissions: 895.1K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 *
 * Example 1:
 *
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 *
 *
 * Note:
 *
 *
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [-231, 231 - 1]
 *
 *
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        unsigned long long p;
        if (n < 0) {
            p = -n;
            x = 1 / x;
        } else {
            p = n;
        }
        while (p) {
            if (p & 1)
                ans *= x;
            x *= x;
            p >>= 1;
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
