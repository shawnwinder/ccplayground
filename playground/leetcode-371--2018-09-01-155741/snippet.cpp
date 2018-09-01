// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.77%)
 * Total Accepted:    108.1K
 * Total Submissions: 212.8K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 *
 *
 * Example 1:
 *
 *
 * Input: a = 1, b = 2
 * Output: 3
 *
 *
 *
 * Example 2:
 *
 *
 * Input: a = -2, b = 3
 * Output: 1
 *
 *
 *
 *
 */
class Solution {
public:
    int getSum(int a, int b) {
        int i = a^b;
        int j = (a&b)<<1;
        while (j != 0) {
            int x = i^j;
            j = (i&j)<<1;
            i = x;
        }
        return i;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
