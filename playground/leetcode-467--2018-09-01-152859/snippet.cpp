// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [467] Unique Substrings in Wraparound String
 *
 * https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (33.28%)
 * Total Accepted:    14.3K
 * Total Submissions: 43.1K
 * Testcase Example:  '"a"'
 *
 * Consider the string s to be the infinite wraparound string of
 * "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 *
 * Now we have another string p. Your job is to find out how many unique
 * non-empty substrings of p are present in s. In particular, your input is the
 * string p and you need to output the number of different non-empty substrings
 * of p in the string s.
 *
 * Note: p consists of only lowercase English letters and the size of p might
 * be over 10000.
 *
 * Example 1:
 *
 * Input: "a"
 * Output: 1
 *
 * Explanation: Only the substring "a" of string "a" is in the string s.
 *
 *
 *
 * Example 2:
 *
 * Input: "cac"
 * Output: 2
 * Explanation: There are two substrings "a", "c" of string "cac" in the string
 * s.
 *
 *
 *
 * Example 3:
 *
 * Input: "zab"
 * Output: 6
 * Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of
 * string "zab" in the string s.
 *
 *
 */
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.empty()) return 0;
        vector<int> m(256, 0);
        int l = 0;
        for (int i=0;i<p.size();i++) {
            if (i > 0 && p[i] - p[i-1] == 1 || p[i] == 'a' && p[i-1] == 'z') {
                l ++;
            } else {
                l = 1;
            }
            m[p[i]] = max(m[p[i]], l);
        }
        int ans = 0;
        for (int i = 'a'; i<='z' ; i ++) {
            ans += m[i];
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
