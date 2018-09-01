// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.96%)
 * Total Accepted:    561.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", which the length is 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int b, e;
        int ret = 0;
        b = 0;
        e = 0;
        while (e < s.size()) {
            while (m.find(s[e]) != m.end()) {
                m.erase(s[b++]);
            }
            m.insert(s[e++]);
            ret = max(ret, e - b);
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
