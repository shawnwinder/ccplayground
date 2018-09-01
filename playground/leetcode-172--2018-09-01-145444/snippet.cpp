// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.00%)
 * Total Accepted:    128.7K
 * Total Submissions: 347.8K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Example 1:
 *
 *
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 *
 * Example 2:
 *
 *
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 */
class Solution {
public:
    int trailingZeroes(int n) {
        long base = 5, cnt = 0;
        while (n / base) {
            cnt += n / base;
            base *= 5;
        }
        return cnt;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
