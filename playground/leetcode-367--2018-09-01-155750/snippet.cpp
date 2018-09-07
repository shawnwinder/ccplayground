// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.85%)
 * Total Accepted:    82.4K
 * Total Submissions: 212K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 14
 * Output: false
 *
 *
 *
 *
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = floor(sqrt(INT_MAX)), y;
        while ((y = (x + num / x) >> 1) < x)
            x = y;
        return x * x == num;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
