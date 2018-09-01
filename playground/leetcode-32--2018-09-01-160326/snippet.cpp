// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>

using namespace std;

/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (23.70%)
 * Total Accepted:    141.3K
 * Total Submissions: 596.4K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 *
 * Example 2:
 *
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        char p[2] = { '(', ')' };
        for (auto i = 0u; i < 2; ++i) {
            int l = 0;
            int r = 0;
            for (char c : s) {
                if (c == p[i])
                    l++;
                else
                    r++;
                if (r == l) {
                    if (l > ret)
                        ret = l;
                } else if (r > l)
                    l = r = 0;
            }
            if (l == r && ret < r)
                ret = r;
            reverse(s.begin(), s.end());
        }
        return ret * 2;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
