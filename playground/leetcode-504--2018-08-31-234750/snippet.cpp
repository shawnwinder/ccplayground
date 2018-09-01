// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (43.91%)
 * Total Accepted:    31.9K
 * Total Submissions: 72.6K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 *
 * Example 1:
 *
 * Input: 100
 * Output: "202"
 *
 *
 *
 * Example 2:
 *
 * Input: -7
 * Output: "-10"
 *
 *
 *
 * Note:
 * The input will be in range of [-1e7, 1e7].
 *
 */
class Solution {
public:
    string convertToBase7(int num) {
        string sign;
        if (num < 0)
        {
            sign = "-";
            num = -num;
        }
        stringstream ss;
        for (auto i=num % 7; num; num /= 7, i = num % 7) {
            ss << i;
        }
        string ret = ss.str();
        reverse(begin(ret), end(ret));
        if (ret.empty())
            return "0";
        return sign + ret;
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
