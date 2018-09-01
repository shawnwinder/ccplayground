// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (28.41%)
 * Total Accepted:    233.3K
 * Total Submissions: 821.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s;
        string r;
        r.reserve(s.size());
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.size(); j += 2 * nRows - 2) {
                r += s[j];
                if (0 < i && i < nRows - 1 && j + (nRows - i - 1) * 2 < s.size())
                    r += s[j + (nRows - i - 1) * 2];
            }
        }
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
