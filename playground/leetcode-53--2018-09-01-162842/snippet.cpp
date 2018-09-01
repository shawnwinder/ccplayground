// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (41.07%)
 * Total Accepted:    357K
 * Total Submissions: 869.1K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN;
        int acc = 0;
        int minacc = 0;
        for (int n : nums) {
            acc += n;
            if (acc - minacc > ret)
                ret = acc - minacc;
            if (acc < minacc)
                minacc = acc;
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
