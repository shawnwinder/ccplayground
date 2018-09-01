// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (29.31%)
 * Total Accepted:    36.2K
 * Total Submissions: 123.7K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * Example:
 *
 *
 * Input: 13
 * Output: 6
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 *
 */
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            int left_mid = n / i;
            int left = left_mid / 10;
            int mid = left_mid % 10;
            int right = n % i;
            if (mid == 0) {
                res += left * i;
            } else if (mid == 1) {
                res += left * i + right + 1;
            } else {
                res += (left + 1) * i;
            }
        }
        return res;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
