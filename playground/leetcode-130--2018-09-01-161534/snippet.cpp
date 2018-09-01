// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (20.56%)
 * Total Accepted:    112.9K
 * Total Submissions: 549.1K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * Example:
 *
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * After running your function, the board should be:
 *
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * Explanation:
 *
 * Surrounded regions shouldn't be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int rows = board.size();
        int cols = board[0].size();
        int pos;
        bool flag;
        vector<vector<bool>> v = vector<vector<bool>>(rows, vector<bool>(cols, false));
        vector<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O' && !v[i][j]) {
                    q.clear();
                    q.push_back(make_pair(i, j));
                    pos = 0;
                    flag = false;
                    while (pos < q.size()) {
                        int next = q.size();
                        for (int s = pos; s < q.size(); s++) {
                            int r = q[s].first;
                            int c = q[s].second;
                            if (v[r][c] || board[r][c] == 'X')
                                continue;
                            v[r][c] = true;
                            if (r == 0)
                                flag = true;
                            else
                                q.push_back(make_pair(r - 1, c));
                            if (r == rows - 1)
                                flag = true;
                            else
                                q.push_back(make_pair(r + 1, c));
                            if (c == 0)
                                flag = true;
                            else
                                q.push_back(make_pair(r, c - 1));
                            if (c == cols - 1)
                                flag = true;
                            else
                                q.push_back(make_pair(r, c + 1));
                        }
                        pos = next;
                    }
                    if (!flag) {
                        for (int k = 0; k < q.size(); ++k) {
                            board[q[k].first][q[k].second] = 'X';
                        }
                    }
                }
            }
        }
    }
};

int mymain(int argc, char* argv[]) { return 0; }
