// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <algorithm>

using namespace std;

/*
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (42.50%)
 * Total Accepted:    20.8K
 * Total Submissions: 49K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string that consists of only uppercase English letters, you can
 * replace any letter in the string with another letter at most k times. Find
 * the length of a longest substring containing all repeating letters you can
 * get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 104.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * s = "ABAB", k = 2
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "AABABBA", k = 1
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ctr[91] = {};
        while (j < s.size()) {
            ctr[s[j++]]++;
            if (j - i - *max_element(ctr + 65, ctr + 91) > k)
                ctr[s[i++]]--;
        }
        return j - i;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
