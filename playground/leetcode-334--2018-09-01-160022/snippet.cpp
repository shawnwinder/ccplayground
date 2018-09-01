// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.52%)
 * Total Accepted:    69.7K
 * Total Submissions: 176.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 *
 * Formally the function should:
 *
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 *
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [5,4,3,2,1]
 * Output: false
 *
 *
 *
 *
 */
 class Solution {
 public:
   bool increasingTriplet(vector<int>& nums) {
     int min1 = INT_MAX;
     int min2 = INT_MAX;
     for (int i = 0; i < nums.size(); i ++) {
       if (nums[i] > min2) return true;
       if (nums[i] > min1 && nums[i] < min2) min2 = nums[i];
       if (nums[i] < min1) min1 = nums[i];
     }
     return false;
   }
 };



int mymain(int argc, char *argv[]) {
    return 0;
}
