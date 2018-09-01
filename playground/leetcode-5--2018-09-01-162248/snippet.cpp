// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.63%)
 * Total Accepted:    363.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string a(2 * s.size() + 1, '#');
        vector<int> p(2 * s.size() + 1);
        for (int i = 0; i < s.size(); i++) {
            a[2 * i + 1] = s[i];
        }
        int c = 0, r = 0;
        int maxv = 0, maxi = -1;
        for (int i = 0; i < a.size(); i++) {
            if (i < r && p[2 * c - i] < r - i) {
                p[i] = p[2 * c - i];
            } else {
                c = i;
                r = i + 1;
                while (r < a.size() && 2 * c - r >= 0 && a[r] == a[2 * c - r])
                    r++;
                p[i] = r - c;
                if (p[i] > maxv) {
                    maxv = p[i];
                    maxi = i;
                }
            }
        }
        return s.substr((maxi - maxv + 1) / 2, maxv - 1);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
