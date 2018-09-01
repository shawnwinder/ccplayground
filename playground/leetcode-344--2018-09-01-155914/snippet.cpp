// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (61.26%)
 * Total Accepted:    286.9K
 * Total Submissions: 468.3K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 *
 * Example 1:
 *
 *
 *
 * Input: "hello"
 * Output: "olleh"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 *
 *
 *
 *
 */
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
