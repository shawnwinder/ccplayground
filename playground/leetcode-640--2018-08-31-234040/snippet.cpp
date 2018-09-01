// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [640] Solve the Equation
 *
 * https://leetcode.com/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (38.71%)
 * Total Accepted:    11.4K
 * Total Submissions: 29.4K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 *
 * Solve a given equation and return the value of x in the form of string
 * "x=#value". The equation contains only '+', '-' operation, the variable x
 * and its coefficient.
 *
 *
 *
 * If there is no solution for the equation, return "No solution".
 *
 *
 * If there are infinite solutions for the equation, return "Infinite
 * solutions".
 *
 *
 * If there is exactly one solution for the equation, we ensure that the value
 * of x is an integer.
 *
 *
 * Example 1:
 *
 * Input: "x+5-3+x=6+x-2"
 * Output: "x=2"
 *
 *
 *
 * Example 2:
 *
 * Input: "x=x"
 * Output: "Infinite solutions"
 *
 *
 *
 * Example 3:
 *
 * Input: "2x=x"
 * Output: "x=0"
 *
 *
 *
 * Example 4:
 *
 * Input: "2x+3x-6x=x+2"
 * Output: "x=-1"
 *
 *
 *
 * Example 5:
 *
 * Input: "x=x+2"
 * Output: "No solution"
 *
 *
 */
class Solution {
public:
    string solveEquation(string equation) {
        string lhs, rhs;
        stringstream ss(equation);
        getline(ss, lhs, '=');
        ss >> rhs;
        
        stringstream ls(lhs);
        int num = 0;
        int coef = 0;
        char op = '+';
        while (true) {
            char c = ls.peek();    
            if (ls.eof()) break;
            if (c == '+' || c == '-') {
                ls >> op;
            } else if (c >= '0' && c <= '9') {
                int i;
                ls >> i;
                if (!ls.eof() && ls.peek() == 'x') {
                    if (op == '+') coef += i; else coef -= i;
                    ls.ignore();
                } else {
                    if (op == '+') num += i; else num -= i;
                }
            } else {
                coef += op=='+'?1:-1;
                ls.ignore();
            }
        }
        num = - num;
        coef = - coef;
        op = '+';
        stringstream rs(rhs);
        while (true) {
            char c = rs.peek();    
            if (rs.eof()) break;
            if (c == '+' || c == '-') {
                rs >> op;
            } else if (c >= '0' && c <= '9') {
                int i;
                rs >> i;
                if (!rs.eof() && rs.peek() == 'x') {
                    if (op == '+') coef += i; else coef -= i;
                    rs.ignore();
                } else {
                    if (op == '+') num += i; else num -= i;
                }
            } else {
                coef += op=='+'?1:-1;
                rs.ignore();
            }
        }
        if (coef == 0) {
            if (num == 0) return "Infinite solutions";
            else return "No solution";
        }
        int x = - num / coef ;
        return "x=" + to_string(x);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
