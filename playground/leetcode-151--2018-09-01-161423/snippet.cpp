// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (15.72%)
 * Total Accepted:    216.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 *
 * Example:  
 *
 *
 * Input: "the sky is blue",
 * Output: "blue is sky the".
 *
 *
 * Note:
 *
 *
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 *
 *
 * Follow up: For C programmers, try to solve it in-place in O(1) space.
 *
 */
class Solution {
public:
    void reverseWords(string &s) {
      size_t i, j = 0;
      for (i = 0; i < s.size(); i++)
        if (s[i] != ' ' || (j && s[j-1] != ' '))
            s[j++] = s[i];
      while (j && s[j-1] == ' ')
        j--;
      s.resize(j);
      reverse(s.begin(), s.end());
      for (size_t i = 0, j; i < s.size(); i = j+1) {
        for (j = i; j < s.size() && s[j] != ' '; j++);
        reverse(s.begin()+i, s.begin()+j);
      }
    }

};

int mymain(int argc, char *argv[]) {
    return 0;
}
