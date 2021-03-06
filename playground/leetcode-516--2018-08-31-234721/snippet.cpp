// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (43.49%)
 * Total Accepted:    38.4K
 * Total Submissions: 88.3K
 * Testcase Example:  '"bbbab"'
 *
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 *
 *
 * Example 1:
 * Input:
 *
 * "bbbab"
 *
 * Output:
 *
 * 4
 *
 * One possible longest palindromic subsequence is "bbbb".
 *
 *
 * Example 2:
 * Input:
 *
 * "cbbd"
 *
 * Output:
 *
 * 2
 *
 * One possible longest palindromic subsequence is "bb".
 *
 */
class Solution {
public:
    // lhs means left hand side, rhs means right hand side
    int longestPalindromeSubseq(string s) {
        if (s.empty())
            return 0;
        vector<vector<int>> longest(s.size(), vector<int>(s.size()));
        for (int len = 1; len <= s.size(); len++) {
            for (int lhs = 0; lhs + len <= s.size(); lhs++) {
                int rhs = lhs + len - 1;
                if (lhs == rhs) {
                    longest[lhs][rhs] = 1;
                } else if (lhs + 1 == rhs) {
                    longest[lhs][rhs] = (s[lhs] == s[rhs]) ? 2 : 1;
                } else {
                    int add = s[lhs] == s[rhs] ? 2 : 0;
                    longest[lhs][rhs] = max(max(longest[lhs][rhs - 1], longest[lhs + 1][rhs]),
                        longest[lhs + 1][rhs - 1] + add);
                }
            }
        }
        return longest[0].back();
    }
};

int mymain(int argc, char* argv[]) { return 0; }
