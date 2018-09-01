// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <algorithm>

using namespace std;

/*
 * [742] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (74.59%)
 * Total Accepted:    20.9K
 * Total Submissions: 28K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "Hello"
 * Output: "hello"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "here"
 * Output: "here"
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "LOVELY"
 * Output: "lovely"
 */
class Solution {
public:
    string toLowerCase(string str) {
        std::transform(std::begin(str), std::end(str), std::begin(str), [](char c) { return std::tolower(c); });
        return str;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}


int mymain(int argc, char *argv[]) {
    return 0;
}
