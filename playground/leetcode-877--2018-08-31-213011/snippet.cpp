// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [909] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (54.93%)
 * Total Accepted:    6.6K
 * Total Submissions: 11.9K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alex and Lee play a game with piles of stones.  There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 *
 * The objective of the game is to end with the most stones.  The total number
 * of stones is odd, so there are no ties.
 *
 * Alex and Lee take turns, with Alex starting first.  Each turn, a player
 * takes the entire pile of stones from either the beginning or the end of the
 * row.  This continues until there are no more piles left, at which point the
 * person with the most stones wins.
 *
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins
 * the game.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [5,3,4,5]
 * Output: true
 * Explanation:
 * Alex starts first, and can only take the first 5 or the last 5.
 * Say he takes the first 5, so that the row becomes [3, 4, 5].
 * If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10
 * points.
 * If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alex, so we
 * return true.
 *
 *
 *
 *
 * Note:
 *
 *
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles) is odd.
 *
 */
class Solution {
public:
    // `dp[i][j]` means the biggest number of stones you can get more than opponent picking piles in
    // `piles[i] ~ piles[j]`. You can first pick `piles[i]` or  `piles[j]`.
    // 1. If you pick `piles[i]`, your result will be `piles[i] - dp[i + 1][j]`
    // 1. If you pick `piles[j]`, your result will be `piles[j] - dp[i][j - 1]`

    // So we get:
    // `dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])`
    // We start from smaller subarray and then we use that to calculate bigger subarray.
    bool stoneGame(vector<int>& piles) {
        vector<int> dp = piles;
        for (int d = 1; d < piles.size(); d++)
            for (int i = 0; i < piles.size() - d; i++)
                dp[i] = max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
        return dp[0] > 0;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
