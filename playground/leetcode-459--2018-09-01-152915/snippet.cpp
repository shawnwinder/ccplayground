// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.55%)
 * Total Accepted:    61.4K
 * Total Submissions: 159.2K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 *
 *
 * Example 2:
 *
 *
 * Input: "aba"
 * Output: False
 *
 *
 * Example 3:
 *
 *
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 *
 *
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> z(n);
        int left = 0;
        int mostRight = 0;
        for (int i=1; i<n; i++) {
            if (i<=mostRight) {
                z[i] = min(mostRight-i+1, z[i-left]);
            } 
            while (i+z[i]<n && s[i+z[i]] == s[z[i]]) {
                z[i]++;
            }
            if (i+z[i]-1>mostRight) {
                mostRight = i+z[i]-1;
                left = i;
            }
        }
        for (int i = 1; i <= n/2; i++) {
            if (z[n-i]+z[i]==n) {
                return true;
            }
        }
        return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
