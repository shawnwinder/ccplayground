// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (44.32%)
 * Total Accepted:    44.9K
 * Total Submissions: 101.4K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 *
 * Find the maximum coins you can collect by bursting the balloons wisely.
 *
 * Note:
 *
 *
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 *
 *
 * Example:
 *
 *
 * Input: [3,1,5,8]
 * Output: 167
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 *
 *
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> n(nums.size()+2);
        n[0] = 1;
        for (int i=1;i<=nums.size();i++) n[i] = nums[i-1];
        n.back() = 1;
        vector<vector<int>> dp(n.size(), vector<int>(n.size(), 0));
        for (int k=2; k<n.size(); k++) {
            for (int i=0; i<n.size() - k; i++) {
                int j = i+k;
                for (int l=i+1; l<j; l++) {
                    dp[i][j] = max(dp[i][j], dp[i][l] + n[i]*n[l]*n[j] + dp[l][j]);
                }
            }
        }
        return dp[0].back();
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
