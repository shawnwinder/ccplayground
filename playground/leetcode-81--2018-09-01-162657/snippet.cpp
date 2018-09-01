// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.50%)
 * Total Accepted:    132.8K
 * Total Submissions: 408.7K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 *
 * Example 1:
 *
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 *
 * Follow up:
 *
 *
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 *
 *
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r-l>>1);
            if (target == nums[mid]) return true;
            if (nums[l] < nums[mid]) { // left is good
                if (nums[l] <= target && target < nums[mid]) r = mid;
                else l = mid + 1;
            } else if (nums[l] > nums[mid]) { // left is broken, so right is good
                if (nums[mid] < target && target <= nums[r]) l = mid+1;
                else r = mid;
            } else l ++; // fix left
        }
        if (nums[l] == target) return true; else return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
