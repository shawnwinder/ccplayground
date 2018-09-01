// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (29.55%)
 * Total Accepted:    127.1K
 * Total Submissions: 430K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 * Note:
 *
 *
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 *
 *
 * Example 1:
 *
 *
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 *
 * Example 2:
 *
 *
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 *
 * Example 3:
 *
 *
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation:
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 */
public class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<Integer>();
        for(int i=0;i<tokens.length;i++){
            String t = tokens[i];
            char op = 'n';
            int num = 0;
            if(t.length()>1) num = Integer.parseInt(t);
            else
            switch(t.charAt(0)){
                case '+':
                case '-':
                case '*':
                case '/':
                    op = t.charAt(0);
                    break;
                default:
                    num = Integer.parseInt(t);
            }
            if(op == 'n') stack.push(num);
            else {
                int b = stack.pop();
                int a = stack.pop();
                int res = 0;
                switch(op) {
                        case '+': res = a+b;break;
                case '-': res = a-b; break;
                case '*': res = a*b; break;
                case '/': res = a/b; break;
                }
                stack.push(res);
            }
        }
        return stack.pop();
    }
}

int mymain(int argc, char *argv[]) {
    return 0;
}
