// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.42%)
 * Total Accepted:    29.7K
 * Total Submissions: 91.5K
 * Testcase Example:  '5'
 *
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 *
 *
 * Example 1:
 *
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 *
 *
 *
 * Example 2:
 *
 * Input: 3
 * Output: False
 *
 *
 *
 */
class Solution {
public:

  bool judgeSquareSum(int c) {
    assert(c >= 0);
    int i = std::floor(std::sqrt(c));
    if (i * i == c) {
      return true;
    } else {
      int j = 1;
      while (j <= i) {
        if (i * i + j * j == c) {
          return true;
        } else if (i * i + j * j < c) {
          j++;
        } else {
          i--;
        }
      }
    }

    return false;
  }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
