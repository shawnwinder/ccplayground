// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.51%)
 * Total Accepted:    43.8K
 * Total Submissions: 120K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 *
 */
class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        char l = s[0];
        int ret = l != ' ';
        for (int i = 1;i<s.size(); i++) {
            if (s[i] != ' ' && l == ' ') ret ++;
            l = s[i];
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
