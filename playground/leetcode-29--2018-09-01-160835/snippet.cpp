// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>

using namespace std;

/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.72%)
 * Total Accepted:    147.8K
 * Total Submissions: 940.2K
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 *
 * Note:
 *
 *
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 231 − 1 when the division
 * result overflows.
 *
 *
 */
class Solution {
public:
    int divide(int p, int q) {
        if (p == INT_MIN && q == -1)
            return INT_MAX;
        bool neg = false;
        int r = 0, c = 0;
        if (p > 0)
            p = -p, neg = !neg;
        if (q > 0)
            q = -q, neg = !neg;
        while (q & 1 << 30 && p <= q << 1)
            q <<= 1, c++;
        for (; c >= 0; c--, q >>= 1)
            if (p <= q) {
                p -= q;
                r += 1 << c;
            }
        return neg ? -r : r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
