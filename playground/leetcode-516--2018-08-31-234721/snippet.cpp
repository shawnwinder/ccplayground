// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
    int longestPalindromeSubseq(string s) {
        string t (s) ;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size()+1, 0));
        for (int i=1; i <= s.size(); i++) {
            for (int j = 1; j<= s.size(); j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (s[i-1] == t[j-1]));
            }
        }
        int ret = 1;
        for (int i = 1; i <s.size(); i++) {
            ret = max(ret, 2 * dp[i][s.size() - i]);
        }
        for (int i = 1; i < s.size() - 1; i ++) {
            ret = max(ret, 1 + 2 * dp[i][s.size() - i - 1]);
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
