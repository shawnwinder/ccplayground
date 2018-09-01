// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.84%)
 * Total Accepted:    193.1K
 * Total Submissions: 926.3K
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        int l = 1, l2 = 1;
        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] =='0') {
                if (s[i-1] > '2' || s[i-1] == '0') return 0;
                swap(l, l2);
            } else {
                if ((s[i] < '7' && s[i-1] == '2') || s[i-1] == '1') {
                    int tmp = l;
                    l += l2;
                    l2 = tmp;
                } else {
                    l2 = l;
                }
            }
        }
        return l;
    }
};



int mymain(int argc, char *argv[]) {
    return 0;
}
