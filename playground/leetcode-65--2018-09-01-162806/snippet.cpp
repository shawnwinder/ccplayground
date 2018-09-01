// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (13.04%)
 * Total Accepted:    94.6K
 * Total Submissions: 725.7K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 *
 */
class Solution {
public:
    bool isNumber(string s) {
        int space = 0;
        int dot = 0;
        int e = 0;
        int num = 0;
        int trail = 0;
        for (auto c:s) {
            if (c == ' ') {
                if (trail != 0) space = 1;
            } else if (c >= '0' && c <= '9') {
                if (space == 1) return false;
                num = 1;
                trail = 1;
            } else if (c == '.') {
                if (dot == 1 || space == 1 || e == 1) return false;
                dot = 1;
                trail = 2;
            } else if (c == 'e') {
                if (num == 0 || e == 1 || space == 1) return false;
                e = 1;
                trail = 3;
            } else if (c == '-' || c == '+') {
                if (space == 1 || (trail != 0 && trail != 3)) return false;
                trail = 4;
            } else return false;
        }
        return trail == 1 || (trail == 2 && num == 1);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
