// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (40.11%)
 * Total Accepted:    27.4K
 * Total Submissions: 68.3K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array which consists of non-negative integers and an integer m, you
 * can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Note:
 * If n is the length of array, assume the following constraints are
 * satisfied:
 *
 * 1 <= n <= 1000
 * 1 <= m <= min(50, n)
 *
 *
 *
 * Examples:
 *
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 *
 * Output:
 * 18
 *
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 */
class Solution {
public:
  int splitArray(vector<int>& a, int m) {
    long l = 0, h = 0;
    for (long i: a) {
      l = max(l, i);
      h += i;
    }
    while (l < h) {
      long x = l+h >> 1, s = 0, n = m;
      for (long i: a) {
          s += i;
          if (s > x) {
              s = i;
              if (n > 0) n --; else break;
          }
      }
      if (n <= 0) // x is smaller than ans
        l = x+1;
      else
        h = x;
    }
    return l;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
