// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>

using namespace std;

/*
 * [488] Zuma Game
 *
 * https://leetcode.com/problems/zuma-game/description/
 *
 * algorithms
 * Hard (36.67%)
 * Total Accepted:    6.8K
 * Total Submissions: 18.5K
 * Testcase Example:  '"WRRBBW"\n"RB"'
 *
 * Think about Zuma Game. You have a row of balls on the table, colored red(R),
 * yellow(Y), blue(B), green(G), and white(W). You also have several balls in
 * your hand.
 *
 * Each time, you may choose a ball in your hand, and insert it into the row
 * (including the leftmost place and rightmost place). Then, if there is a
 * group of 3 or more balls in the same color touching, remove these balls.
 * Keep doing this until no more balls can be removed.
 *
 * Find the minimal balls you have to insert to remove all the balls on the
 * table. If you cannot remove all the balls, output -1.
 *
 *
 * Examples:
 * Input: "WRRBBW", "RB"
 * Output: -1
 * Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
 *
 * Input: "WWRRBBWW", "WRBRW"
 * Output: 2
 * Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW ->
 * empty
 *
 * Input:"G", "GGGGG"
 * Output: 2
 * Explanation: G -> G[G] -> GG[G] -> empty
 *
 * Input: "RBYYBBRRB", "YRBGB"
 * Output: 3
 * Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] ->
 * BB[B] -> empty
 *
 *
 *
 * Note:
 *
 * You may assume that the initial row of balls on the table won't have any 3
 * or more consecutive balls with the same color.
 * The number of balls on the table won't exceed 20, and the string represents
 * these balls is called "board" in the input.
 * The number of balls in your hand won't exceed 5, and the string represents
 * these balls is called "hand" in the input.
 * Both input strings will be non-empty and only contain characters
 * 'R','Y','B','G','W'.
 *
 *
 */
class Solution {
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int res = helper(board, hand);
        return res > hand.size() ? -1 : res;
    }

    long helper(string& b, string& h) {
        if (b.empty())
            return 0;
        if (h.empty())
            return INT_MAX;
        long res = INT_MAX;
        for (int i = 0; i < h.size(); i++) {
            int j = 0;
            int n = b.size();
            while (j < n) {
                int k = b.find(h[i], j);
                if (k == string::npos)
                    break;
                if (k < n - 1 && b[k] == b[k + 1]) {
                    string nextb = shrink(b.substr(0, k) + b.substr(k + 2));
                    if (nextb.empty())
                        return 1;
                    string nexth = h;
                    nexth.erase(i, 1);
                    res = min(res, helper(nextb, nexth) + 1);
                    k++;
                } else if (i > 0 && h[i] == h[i - 1]) {
                    string nextb = shrink(b.substr(0, k) + b.substr(k + 1));
                    if (nextb.empty())
                        return 2;
                    string nexth = h;
                    nexth.erase(i, 1);
                    nexth.erase(i - 1, 1);
                    res = min(res, helper(nextb, nexth) + 2);
                }
                j = k + 1;
            }
        }
        return res;
    }

    string shrink(string s) {
        while (s.size() > 0) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= s.size(); i++) {
                if (i == s.size() || s[i] != s[start]) {
                    if (i - start >= 3) {
                        s = s.substr(0, start) + s.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if (done)
                break;
        }
        return s; // NVRO
    }
};

int mymain(int argc, char* argv[]) { return 0; }
