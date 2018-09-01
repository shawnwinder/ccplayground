// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <numeric>

using namespace std;

/*
 * [910] Nth Magical Number
 *
 * https://leetcode.com/problems/nth-magical-number/description/
 *
 * algorithms
 * Hard (22.36%)
 * Total Accepted:    2.6K
 * Total Submissions: 11.7K
 * Testcase Example:  '1\n2\n3'
 *
 * A positive integer is magical if it is divisible by either A or B.
 *
 * Return the N-th magical number.  Since the answer may be very large, return
 * it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: N = 1, A = 2, B = 3
 * Output: 2
 *
 *
 *
 * Example 2:
 *
 *
 * Input: N = 4, A = 2, B = 3
 * Output: 6
 *
 *
 *
 * Example 3:
 *
 *
 * Input: N = 5, A = 2, B = 4
 * Output: 10
 *
 *
 *
 * Example 4:
 *
 *
 * Input: N = 3, A = 6, B = 4
 * Output: 8
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 10^9
 * 2 <= A <= 40000
 * 2 <= B <= 40000
 *
 */
class Solution {
public:
    // 1. Get gcd (greatest common divisor) and lcm (least common multiple) of (A, B).

    // 2. How many magic numbers `<= x` ?
    // By inclusion exclusion principle, we have:
    // `x / A + x / B - x / lcm`

    // 3. Set our binary search range
    // Lower bound is `min(A, B)`
    // Upper bound is `N * min(A, B)`

    // 4. binary search, find the smallest `x` that `x / A + x / B - x / lcm = N`
    int nthMagicalNumber(int N, int A, int B) {
        long lcm = (A * B) / __gcd(A, B), l = min(A, B), r = N * l, mod = 1e9 + 7;
        while (l < r) {
            long m = (l + r) / 2;
            if (m / A + m / B - m / lcm < N)
                l = m + 1;
            else
                r = m;
        }
        return l % mod;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
