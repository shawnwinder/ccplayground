// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [928] Surface Area of 3D Shapes
 *
 * https://leetcode.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (55.24%)
 * Total Accepted:    3.1K
 * Total Submissions: 5.6K
 * Testcase Example:  '[[2]]'
 *
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 *
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of
 * grid cell (i, j).
 *
 * Return the total surface area of the resulting shapes.
 *
 *
 * Example 1:
 *
 *
 * Input: [[2]]
 * Output: 10
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,2],[3,4]]
 * Output: 34
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [[1,0],[0,2]]
 * Output: 16
 *
 *
 *
 * Example 4:
 *
 *
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 32
 *
 *
 *
 * Example 5:
 *
 *
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 46
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 *
 */
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0, n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j])
                    res += grid[i][j] * 4 + 2;
                if (i)
                    res -= min(grid[i][j], grid[i - 1][j]) * 2;
                if (j)
                    res -= min(grid[i][j], grid[i][j - 1]) * 2;
            }
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
