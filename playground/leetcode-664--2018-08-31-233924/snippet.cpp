// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [664] Strange Printer
 *
 * https://leetcode.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (34.76%)
 * Total Accepted:    6.2K
 * Total Submissions: 17.9K
 * Testcase Example:  '"aaabbb"'
 *
 *
 * There is a strange printer with the following two special requirements:
 *
 *
 * The printer can only print a sequence of the same character each time.
 * At each turn, the printer can print new characters starting from and ending
 * at any places, and will cover the original existing characters.
 *
 *
 *
 *
 *
 * Given a string consists of lower English letters only, your job is to count
 * the minimum number of turns the printer needed in order to print it.
 *
 *
 * Example 1:
 *
 * Input: "aaabbb"
 * Output: 2
 * Explanation: Print "aaa" first and then print "bbb".
 *
 *
 *
 * Example 2:
 *
 * Input: "aba"
 * Output: 2
 * Explanation: Print "aaa" first and then print "b" from the second place of
 * the string, which will cover the existing character 'a'.
 *
 *
 *
 * Hint: Length of the given string will not exceed 100.
 */
class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        s.erase(unique(s.begin(), s.end()), s.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0;i<n;i++) dp[i][i] = 1;
        for (int i=1;i<n;i++) {
            for (int j=0;j<n-i;j++) {
                int k = j + i;
                int temp = i + 1;
                for (int l = j;l<k;l++) {
                    temp = min(temp, dp[j][l] + dp[l+1][k]);
                }
                if (s[j] == s[k]) temp --;
                dp[j][k] = temp;
            }
        }
        return dp[0][n-1];
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
