// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (27.33%)
 * Total Accepted:    156.7K
 * Total Submissions: 573.4K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.back();
        int minp = nums[0];
        int maxp = nums[0];
        int ret = maxp;
        for (int i=1;i<nums.size();i++) {
            int lminp = minp;
            minp = min(nums[i], maxp * nums[i]);
            minp = min(minp, lminp * nums[i]);
            maxp = max(nums[i], maxp * nums[i]);
            maxp = max(maxp, lminp * nums[i]);
            if (maxp > ret) ret = maxp;
        }
        return ret;
        
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
