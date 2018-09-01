// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (48.32%)
 * Total Accepted:    81.7K
 * Total Submissions: 169K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an nxn chessboard
 * such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 * Example:
 *
 *
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 *  [".Q..",  // Solution 1
 *  "...Q",
 *  "Q...",
 *  "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *  "Q...",
 *  "...Q",
 *  ".Q.."]
 * ]
 *
 */
class Solution {
public:
    void valid(vector<int>& b, int& ans, int n) {
        if (b.size() == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            bool flag = false;
            int c = b.size();
            for (int r : b) {
                if (r == i || c + r == i || c + i == r) {
                    flag = true;
                    break;
                }
                c--;
            }
            if (!flag) {
                b.push_back(i);
                valid(b, ans, n);
                b.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> b;
        valid(b, ans, n);
        return ans;
    }
};
int mymain(int argc, char* argv[]) { return 0; }
