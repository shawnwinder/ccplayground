// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (25.90%)
 * Total Accepted:    90.6K
 * Total Submissions: 349.8K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 *
 * Example 1:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 *
 *
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                dp[i][j] = (i && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    || (j && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                dp[0][0] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int mymain(int argc, char* argv[]) { return 0; }
