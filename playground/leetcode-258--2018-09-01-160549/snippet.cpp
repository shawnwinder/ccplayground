// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (52.52%)
 * Total Accepted:    208.9K
 * Total Submissions: 397.9K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 *
 * Example:
 *
 *
 * Input: 38
 * Output: 2
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
 * Since 2 has only one digit, return it.
 *
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 */
class Solution {
public:
    int addDigits(int num) { return num - 9 * ((num - 1) / 9); }
};

int mymain(int argc, char* argv[]) { return 0; }
