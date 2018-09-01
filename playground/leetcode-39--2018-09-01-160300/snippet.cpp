// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (43.25%)
 * Total Accepted:    246.6K
 * Total Submissions: 570K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */
class Solution {
public:
    void work(vector<vector<int>>& ans, vector<int>& partial, int i, vector<int>& candidates,
        int target) {
        if (target == 0) {
            ans.push_back(partial);
            return;
        }
        if (i >= candidates.size() || candidates[i] > target)
            return;
        partial.push_back(candidates[i]);
        work(ans, partial, i, candidates, target - candidates[i]);
        partial.pop_back();
        // mimic loop
        work(ans, partial, i + 1, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> partial;
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        work(ret, partial, 0, candidates, target);
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
