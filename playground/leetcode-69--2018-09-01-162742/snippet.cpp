// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <cmath>

using namespace std;

/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.43%)
 * Total Accepted:    263.6K
 * Total Submissions: 895.6K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */
class Solution {
public:
    // The key point is the average result is calculate by "ans = (ans + x / ans) / 2";
    // For instance, when calculate sqrt(2) :
    //        Guess Result        Quotient                             Average Result
    //               1          2 / 1 = 2                            (2 + 1) / 2 = 1.5
    //              1.5      2 / 1.5 = 1.3333                (1.3333 + 1.5) / 2 = 1.4167
    //            1.4167    2 / 1.4167 = 1.4118          (1.4167 + 1.4118) / 2 = 1.4142
    int mySqrt(int x) {
        double ans = x;
        double delta = 0.0001;
        while (fabs(pow(ans, 2) - x) > delta) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
