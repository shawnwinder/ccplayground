// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (37.78%)
 * Total Accepted:    210.3K
 * Total Submissions: 556.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 *
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        vector<int> loc;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visit (row, vector<bool>(col));
        int ret = 0;
        vector<pair<int, int>> dirs = { { -1, 0} , {1, 0}, {0, -1}, {0, 1}};
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j] == '0' || visit[i][j]) continue;
                ret ++;
                loc.push_back(i*col + j);
                visit[i][j] = true;
                while (!loc.empty()) {
                    int p = loc.back(); loc.pop_back();
                    int x = p / col, y = p % col;
                    for (auto& d : dirs) {
                        int x2 = d.first + x, y2 = d.second + y;
                        if (x2 < 0 || x2 >= row || y2 < 0 || y2 >= col || visit[x2][y2] || grid[x2][y2] == '0') continue;
                        visit[x2][y2] = true;
                        loc.push_back(x2 * col + y2);
                    }
                }
            }
        }
        return ret;
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
