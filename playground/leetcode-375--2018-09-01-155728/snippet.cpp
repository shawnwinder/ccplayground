// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (36.24%)
 * Total Accepted:    34.3K
 * Total Submissions: 94.7K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 *
 * However, when you guess a particular number x,  and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 *
 *
 * Example:
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 *
 *
 *
 * Given a particular n >= 1, find out how much money you need to have to
 * guarantee a win.
 *
 * Credits:Special thanks to @agave and @StefanPochmann for adding this problem
 * and creating all test cases.
 */
class Solution {
public:
    // TODO http://artofproblemsolving.com/community/c296841h1273742
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int k = 1; k < n; k++) {
            for (int i = 1; i <= n - k; i++) {
                int j = i + k;
                dp[i][j] = min(dp[i][j - 1] + j, dp[i + 1][j] + i);
                for (int l = i + 1; l < j; l++) {
                    dp[i][j] = min(dp[i][j], l + max(dp[i][l - 1], dp[l + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};

int mymain(int argc, char* argv[]) { return 0; }
