// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.99%)
 * Total Accepted:    64.3K
 * Total Submissions: 146.2K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 *
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 *
 *
 * Example 1:
 *
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 *
 *
 *
 * Note:
 *
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 *
 *
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> dp(2002, 0);
        if (S > 1000 || S < -1000) return 0;
        dp[1000] = 1;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> dp2(2002, 0);
            for (int j = 0; j<2002 - nums[i]; j ++) {
                dp2[nums[i] + j] = dp[j];
            }
            for (int j = 2001; j >= nums[i]; j--) {
                dp2[j - nums[i]] += dp[j];
            }
            swap(dp, dp2);
        }
        return dp[S + 1000];
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
