// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

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
    int advanceBy(int step, int j, vector<int>& nums, int dir) {
        int n = nums.size();
        for (; step > 0; step--) {
            j = (j + nums[j] + n) % n;
            if (nums[j] * dir <= 0)
                return -1;
        }
        return j;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        bool loop = false;
        for (int i = 0; i < nums.size() && !loop; i++)
            if (nums[i]) {
                int j1 = i, j2 = i, dir = nums[i];
                do {
                    j1 = advanceBy(1, j1, nums, dir);
                    j2 = advanceBy(2, j2, nums, dir);
                } while (j1 >= 0 && j2 >= 0 && j1 != j2);
                if (j1 >= 0 && j2 >= 0 && j1 == j2) {
                    if (j1 == advanceBy(1, j1, nums, dir))
                        nums[j1] = 0;
                    else
                        loop = true;
                }
                nums[i] = 0;
            }
        return loop;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
