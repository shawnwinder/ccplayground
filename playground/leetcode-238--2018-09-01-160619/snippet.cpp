// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (51.42%)
 * Total Accepted:    173.7K
 * Total Submissions: 337.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Example:
 *
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 *
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 *
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> o(n);
        o[0] = 1;
        for(int i=1;i<n;i++) {
            o[i] = nums[i-1]*o[i-1];
        }
        int pro = nums[n-1];
        for(int i=n-2;i>=0;i--){
            o[i] = pro*o[i];
            pro *= nums[i];
        }
        return o;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
