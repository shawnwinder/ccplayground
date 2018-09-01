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

func decodeString(s string) string {
	istack := []int{1}
	dstack := [][]byte{{}}
	num := 0
	for _, c := range []byte(s) {
		switch {
		case c >= '0' && c <= '9':
			num = num*10 + int(c-'0')
		case c == '[':
			istack = append(istack, num)
			num = 0
			dstack = append(dstack, []byte{})
		case c >= 'a' && c <= 'z':
			dstack[len(dstack)-1] = append(dstack[len(dstack)-1], c)
		case c == ']':
			for i := 0; i < istack[len(istack)-1]; i++ {
				dstack[len(dstack)-2] = append(dstack[len(dstack)-2], dstack[len(dstack)-1]...)
			}
			istack = istack[:len(istack)-1]
			dstack = dstack[:len(dstack)-1]
		}
	}
	return string(dstack[0])
}



int mymain(int argc, char *argv[]) {
    return 0;
}
