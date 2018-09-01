// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (39.50%)
 * Total Accepted:    22.2K
 * Total Submissions: 56.3K
 * Testcase Example:  '[4,6,7,7]'
 *
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2 .
 *
 *
 * Example:
 *
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 *
 *
 *
 * Note:
 *
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 *
 *
 */
class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& partial, vector<int>& nums, int i) {
        if (i == nums.size()) {
            if (partial.size() >= 2) ans.push_back(partial);
            return;
        }
        bool flag = false;
        if (partial.empty() || partial.back() <= nums[i]) {
            partial.push_back(nums[i]);
            solve(ans, partial, nums,i+1);
            partial.pop_back();
            if (partial.back() == nums[i]) flag = true;
        }
        solve(ans, partial, nums, i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> partial;
        solve(ans, partial, nums, 0);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
