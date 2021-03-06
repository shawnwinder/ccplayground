// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (42.16%)
 * Total Accepted:    64.7K
 * Total Submissions: 153.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 *
 * Given an encoded string, return it's decoded string.
 *
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 */

class Solution {
    string decodeString(const string& s, int& i) {
        string res;
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                while (n-- > 0)
                    res += t;
            }
        }
        return res;
    }

public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
