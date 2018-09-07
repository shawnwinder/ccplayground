// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <algorithm>

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
        if (num < 0)
            return '-' + convertToBase7(-num);
        string r;
        do
            r.push_back(num % 7 + '0');
        while (num /= 7);
        reverse(begin(r), end(r));
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
