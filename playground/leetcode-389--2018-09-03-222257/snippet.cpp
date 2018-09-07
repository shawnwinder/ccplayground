// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (51.82%)
 * Total Accepted:    117.6K
 * Total Submissions: 226.9K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 *
 * Given two strings s and t which consist of only lowercase letters.
 *
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 *
 * Find the letter that was added in t.
 *
 * Example:
 *
 * Input:
 * s = "abcd"
 * t = "abcde"
 *
 * Output:
 * e
 *
 * Explanation:
 * 'e' is the letter that was added.
 *
 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r = 0;
        for (char c : s)
            r ^= c;
        for (char c : t)
            r ^= c;
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }