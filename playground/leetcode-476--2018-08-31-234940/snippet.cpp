// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <cmath>

using namespace std;

/*
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (61.34%)
 * Total Accepted:    87.5K
 * Total Submissions: 142.7K
 * Testcase Example:  '5'
 *
 * Given a positive integer, output its complement number. The complement
 * strategy is to flip the bits of its binary representation.
 *
 * Note:
 *
 * The given integer is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You could assume no leading zero bit in the integer's binary
 * representation.
 *
 *
 *
 * Example 1:
 *
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 *
 *
 *
 * Example 2:
 *
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 *
 *
 */
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0 << (32 - __builtin_clz(num));
        return ~mask & ~num;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}


int mymain(int argc, char *argv[]) {
    return 0;
}
