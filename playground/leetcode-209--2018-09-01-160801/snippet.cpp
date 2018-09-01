// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (32.99%)
 * Total Accepted:    134.6K
 * Total Submissions: 408K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 *
 * Example: 
 *
 *
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 *
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (r<nums.size()) {
            sum += nums[r++];
            while (sum >= s) {
                ans = min(r-l, ans);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX?0:ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
