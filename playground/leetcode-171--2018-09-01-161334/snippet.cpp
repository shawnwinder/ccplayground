// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (49.58%)
 * Total Accepted:    183.2K
 * Total Submissions: 369.5K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *
 *
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28
 * ⁠   ...
 *
 *
 * Example 1:
 *
 *
 * Input: "A"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: "AB"
 * Output: 28
 *
 *
 * Example 3:
 *
 *
 * Input: "ZY"
 * Output: 701
 *
 *
 */
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (char c : s) {
            ret = ret * 26 + c - 'A' + 1;
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
