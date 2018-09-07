// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (36.39%)
 * Total Accepted:    80.1K
 * Total Submissions: 220.1K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 *
 * Example 1:
 *
 *
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 *
 *
 * Example 2:
 *
 *
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 *
 *
 * Example 3:
 *
 *
 * Input: ")("
 * Output: [""]
 *
 *
 */
class Solution {
public:
    unordered_set<string> res;
    void f(const string& s, string ss, int k, int left, int right, int state) {
        if (k == s.size()) {
            if (!left && !right && !state)
                res.insert(ss);
            return;
        }
        if (s[k] == '(') {
            if (left > 0)
                f(s, ss, k + 1, left - 1, right, state);
            f(s, ss + '(', k + 1, left, right, state + 1);
        } else if (s[k] == ')') {
            if (right > 0)
                f(s, ss, k + 1, left, right - 1, state);
            if (state > 0)
                f(s, ss + ')', k + 1, left, right, state - 1);
        } else
            f(s, ss + s[k], k + 1, left, right, state);
    }

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (auto c : s)
            if (c == '(')
                l++;
            else if (c == ')')
                l ? l-- : r++;
        f(s, "", 0, l, r, 0);
        return vector<string>(res.begin(), res.end());
    }
};

int mymain(int argc, char* argv[]) { return 0; }
