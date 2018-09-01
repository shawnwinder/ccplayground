// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (36.13%)
 * Total Accepted:    30.6K
 * Total Submissions: 84.6K
 * Testcase Example:  '"aaabb"\n3'
 *
 *
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 *
 *
 * Example 1:
 *
 * Input:
 * s = "aaabb", k = 3
 *
 * Output:
 * 3
 *
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "ababbc", k = 2
 *
 * Output:
 * 5
 *
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 *
 *
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        if (k <= 1) return s.size();
        for (int t = 1; t <= 26; t++) {
            int l = 0;
            int r = 0;
            int valid = 0;
            int num = 0;
            unordered_map<char, int> m;
            while (r < s.size()) {
                if (num <= t) {
                    int& c = m[s[r]];
                    c ++;
                    if (c == 1) num ++;
                    if (c == k) valid ++;
                    r ++;
                } else {
                    int& c = m[s[l]];
                    if (c == 1) num --;
                    if (c == k) valid --;
                    c --;
                    l ++;
                }
                if (valid == num) ans = max(ans, r - l);
            }
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
