// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (49.86%)
 * Total Accepted:    239.7K
 * Total Submissions: 480.9K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 *  "((()))",
 *  "(()())",
 *  "(())()",
 *  "()(())",
 *  "()()()"
 * ]
 *
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string state;
        solve(ans, state, n, n);
        return ans;
    }

    void solve(vector<string>& ans, string state, int l, int r) {
        if (l == 0 && r == 0) {
            ans.push_back(std::move(state));
            return;
        }
        if (l > 0) {
            solve(ans, state + '(', l - 1, r);
        }
        if (r > l) {
            solve(ans, state + ')', l, r - 1);
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
