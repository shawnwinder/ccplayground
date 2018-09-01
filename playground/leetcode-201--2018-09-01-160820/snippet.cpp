// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (34.86%)
 * Total Accepted:    70.2K
 * Total Submissions: 201.3K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 *
 * Example 1:
 *
 *
 * Input: [5,7]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1]
 * Output: 0
 *
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) { return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m; }
};

int mymain(int argc, char* argv[]) { return 0; }
