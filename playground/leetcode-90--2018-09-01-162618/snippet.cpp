// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (39.52%)
 * Total Accepted:    162.2K
 * Total Submissions: 410.4K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 *  [2],
 *  [1],
 *  [1,2,2],
 *  [2,2],
 *  [1,2],
 *  []
 * ]
 *
 */
class Solution {
public:
    void work(vector<vector<int>>& ans, vector<int>& partial, int i, vector<int>& candidates) {
        if (i >= candidates.size()) {
            ans.push_back(partial);
            return;
        }
        partial.push_back(candidates[i]);
        work(ans, partial, i + 1, candidates);
        partial.pop_back();
        i++;
        while (i < candidates.size() && candidates[i] == candidates[i - 1])
            i++;
        work(ans, partial, i, candidates);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> partial;
        work(ans, partial, 0, nums);
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
