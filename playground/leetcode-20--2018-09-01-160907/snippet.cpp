// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.50%)
 * Total Accepted:    387.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
class Solution {
public:
    bool isValid(string s) {
        vector<char> st = { '^' };
        unordered_map<char, char> m = { { '{', '}' }, { '[', ']' }, { '(', ')' } };
        for (char x : s) {
            if (x == '{' || x == '(' || x == '[')
                st.push_back(x);
            else if (x != m[st.back()])
                return false;
            else
                st.pop_back();
        }
        return st.size() == 1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
