// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (48.51%)
 * Total Accepted:    98.2K
 * Total Submissions: 202.5K
 * Testcase Example:  '3\n7'
 *
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 * Note:
 *
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 *
 */
class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& state, int s, int i, int k, int n) {
        if (k == 0) {
            if (s == n)
                ans.push_back(state);
            return;
        }
        if (9 - i + 1 < k)
            return;
        for (int j = i; j <= 9; j++) {
            if (s + (2 * j + k - 1) * k / 2 > n)
                break;
            state.push_back(j);
            solve(ans, state, s + j, j + 1, k - 1, n);
            state.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> state;
        solve(ret, state, 0, 1, k, n);
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
