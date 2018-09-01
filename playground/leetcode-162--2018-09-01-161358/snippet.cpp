// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (39.63%)
 * Total Accepted:    175.9K
 * Total Submissions: 443.9K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */
 class Solution {
 public:
   int findPeakElement(vector<int>& nums) {
     deque<int> anums(nums.begin(), nums.end());
     anums.push_front(INT_MIN);
     anums.push_back(INT_MIN);
     int s = 1;
     int t = nums.size();
     while (s < t) {
       int mid = s + (t-s) / 2;
       int v = anums[mid];
       if (v<=anums[mid + 1]) {
         s = mid + 1;
       } else if (anums[mid-1] >= v) {
         t = mid;
       } else return mid - 1;
     }
     return s - 1;
   }
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
