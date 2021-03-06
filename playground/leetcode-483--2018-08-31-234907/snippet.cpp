// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <cmath>

using namespace std;

/*
 * [483] Smallest Good Base
 *
 * https://leetcode.com/problems/smallest-good-base/description/
 *
 * algorithms
 * Hard (33.59%)
 * Total Accepted:    8.2K
 * Total Submissions: 24.4K
 * Testcase Example:  '"13"'
 *
 * For an integer n, we call k>=2 a good base of n, if all digits of n base k
 * are 1.
 * Now given a string representing n, you should return the smallest good base
 * of n in string format.
 *
 * Example 1:
 *
 * Input: "13"
 * Output: "3"
 * Explanation: 13 base 3 is 111.
 *
 *
 *
 * Example 2:
 *
 * Input: "4681"
 * Output: "8"
 * Explanation: 4681 base 8 is 11111.
 *
 *
 *
 * Example 3:
 *
 * Input: "1000000000000000000"
 * Output: "999999999999999999"
 * Explanation: 1000000000000000000 base 999999999999999999 is 11.
 *
 *
 *
 * Note:
 *
 * The range of n is [3, 10^18].
 * The string representing n is always valid and will not have leading zeros.
 *
 *
 */
class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long num = stol(n);
        for (int m = 63 - __builtin_clz(num); m > 1; m--) {
            unsigned long x = pow(num, 1.0 / m), s = 1, c = 1;
            if (x > 1) {
                for (int i = m; i--;)
                    s += c *= x;
                if (s == num)
                    return to_string(x);
            }
        }
        return to_string(num - 1);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
