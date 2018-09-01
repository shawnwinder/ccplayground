// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (34.02%)
 * Total Accepted:    38.1K
 * Total Submissions: 111.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 *
 * Si % Sj = 0 or Sj % Si = 0.
 *
 * If there are multiple solutions, return any subset is fine.
 *
 * Example 1:
 *
 *
 *
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 *
 *
 *
 *
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(nums.size());
        vector<int> ret;
        for (int i = 0;i < nums.size();++i) {
            for (int j = 0;j < i;++j) {
                if (nums[i] % nums[j] == 0 && result[j].size() > result[i].size()) {
                    result[i] = result[j];
                }
            }
            result[i].push_back(nums[i]);
            if (ret.size() < result[i].size()) ret = result[i];
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
