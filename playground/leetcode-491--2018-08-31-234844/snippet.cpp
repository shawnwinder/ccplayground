// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> r;
        for (auto i = 0u; i < 1 << n; ++i) {
            int last = INT_MIN;
            vector<int> a;
            for (auto j = 0u; j < n; ++j)
                if (i >> j & 1) {
                    if (last > nums[j]) {
                        a.clear();
                        break;
                    }
                    a.push_back(last = nums[j]);
                }
            if (a.size() > 1)
                r.push_back(a);
        }
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
