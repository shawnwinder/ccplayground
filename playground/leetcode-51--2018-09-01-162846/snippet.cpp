// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (34.90%)
 * Total Accepted:    109.6K
 * Total Submissions: 314.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an nxn chessboard
 * such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * Example:
 *
 *
 * Input: 4
 * Output: [
 * [".Q..",  // Solution 1
 *  "...Q",
 *  "Q...",
 *  "..Q."],
 *
 * ["..Q.",  // Solution 2
 *  "Q...",
 *  "...Q",
 *  ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 *
 *
 */
class Solution {
public:
    void valid(vector<int>& b, vector<string>& state, vector<vector<string>>& ans, int n) {
        if (b.size() == n) {
            ans.push_back(state);
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
                state[b.size()][i] = 'Q';
                b.push_back(i);
                valid(b, state, ans, n);
                b.pop_back();
                state[b.size()][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> b;
        vector<string> state(n, string(n, '.'));
        vector<vector<string>> ans;
        valid(b, state, ans, n);
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
