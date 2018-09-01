// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (47.22%)
 * Total Accepted:    268.2K
 * Total Submissions: 568.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *
 */
// To give all the possible subsets, we just need to exhaust all the possible combinations of the
// numbers. And each number has only two possibilities: either in or not in a subset. And this can
// be represented using a bit. Using `[1, 2, 3]` as an example, `1` appears once in every two
// consecutive subsets, `2` appears twice in every four consecutive subsets, and `3` appears four
// times in every eight subsets (initially all subsets are empty):
// `[], [], [], [], [], [], [], []`
// `[], [1], [], [1], [], [1], [], [1]`
// `[], [1], [2], [1, 2], [], [1], [2], [1, 2]`
// `[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]`
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size());
        vector<vector<int>> subs(n, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < n; j++) {
                if ((j >> i) & 1) {
                    subs[j].push_back(nums[i]);
                }
            }
        }
        return subs;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
