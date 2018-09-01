// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.08%)
 * Total Accepted:    209.6K
 * Total Submissions: 653.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * Example:
 *
 * Input: "Hello World"
 * Output: 5
 *
 *
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string t;
        string l;
        while (ss >> t) {
            if (t == "") break;
            l = t;
        }
        return l.size();
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
