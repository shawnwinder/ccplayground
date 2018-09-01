// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (61.36%)
 * Total Accepted:    85.9K
 * Total Submissions: 140K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 *
 *
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 *
 */
class Solution {
public:
    string reverseWords(string s) {
        stringstream i(s);
        stringstream o;
        string tmp;
        while(getline(i, tmp, ' ')) {
            reverse(tmp.begin(), tmp.end());
            o << tmp << " ";
        }
        string ret = o.str();
        ret.pop_back();
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
