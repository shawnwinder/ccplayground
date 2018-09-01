// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (36.54%)
 * Total Accepted:    183.4K
 * Total Submissions: 502K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 *  [1,1,2],
 *  [1,2,1],
 *  [2,1,1]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        while (true) {
            int i;
            for (i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1])
                    break;
            }
            reverse(nums.begin() + i + 1, nums.end());
            if (i == -1) {
                res.push_back(nums);
                break;
            } else {
                auto it = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
                swap(nums[i], *it);
                res.push_back(nums);
            }
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
