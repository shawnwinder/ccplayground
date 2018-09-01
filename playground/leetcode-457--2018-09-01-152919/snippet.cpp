// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [457] Circular Array Loop
 *
 * https://leetcode.com/problems/circular-array-loop/description/
 *
 * algorithms
 * Medium (23.84%)
 * Total Accepted:    7.8K
 * Total Submissions: 32.5K
 * Testcase Example:  '[2, -1, 1, 2, 2]'
 *
 * You are given an array of positive and negative integers. If a number n at
 * an index is positive, then move forward n steps. Conversely, if it's
 * negative (-n), move backward n steps. Assume the first element of the array
 * is forward next to the last element, and the last element is backward next
 * to the first element. Determine if there is a loop in this array. A loop
 * starts and ends at a particular index with more than 1 element along the
 * loop. The loop must be "forward" or "backward'.
 *
 * Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0
 * -> 2 -> 3 -> 0.
 *
 * Example 2: Given the array [-1, 2], there is no loop.
 *
 * Note: The given array is guaranteed to contain no element "0".
 *
 * Can you do it in O(n) time complexity and O(1) space complexity?
 *
 */
class Solution {
public:
  int move(int a, int b, int c) {
    return ((a + b) % c + c) % c;
  }
  bool traverse(int i, vector<int>& nums) {
    int len = nums.size();
    if (nums[i] == 0) return false;
    int one = i, two = i;
    do {
      int last = one;
      cout << "one: " << one << " ---> ";
      one = move(one, nums[one], len);
      cout << one << endl;
      if (one == last) return false;
      if (nums[one] == 0) return false;
      if (nums[one] * nums[last] < 0) return false;
      cout << "two: " << two << " ---> ";
      two = move(two, nums[two], len);
      last = two;
      two = move(two, nums[two], len);
      if (two == last) return false;
      if (nums[two] * nums[last] < 0) return false;
      cout << two << endl;
      if (nums[two] == 0) return false;
    } while (one != two);
    return true;
  }

  bool circularArrayLoop(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) continue;
      if (traverse(i, nums)) return true;
      nums[i] = 0;
    }
    return false;
  }
};



int mymain(int argc, char *argv[]) {
    return 0;
}
