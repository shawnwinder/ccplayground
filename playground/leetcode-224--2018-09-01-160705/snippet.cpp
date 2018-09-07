// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <stack>

using namespace std;

/*
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (29.63%)
 * Total Accepted:    74.5K
 * Total Submissions: 251.3K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 *
 * Example 1:
 *
 *
 * Input: "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: " 2-1 + 2 "
 * Output: 3
 *
 * Example 3:
 *
 *
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 *
 *
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 *
 *
 */
class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else {
                rst += sign * num;
                num = 0;
                if (c == '+')
                    sign = 1;
                if (c == '-')
                    sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
