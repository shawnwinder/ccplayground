// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (37.52%)
 * Total Accepted:    168.8K
 * Total Submissions: 450K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
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
        work(ans, partial, i + 1, candidates, target - candidates[i]);
        partial.pop_back();
        i++;
        // all duplicates are done
        while (i < candidates.size() && candidates[i] == candidates[i - 1])
            i++;
        work(ans, partial, i, candidates, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> partial;
        sort(candidates.begin(), candidates.end());
        work(ret, partial, 0, candidates, target);
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
