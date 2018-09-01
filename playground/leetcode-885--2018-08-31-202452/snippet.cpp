// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [921] Spiral Matrix III
 *
 * https://leetcode.com/problems/spiral-matrix-iii/description/
 *
 * algorithms
 * Medium (64.31%)
 * Total Accepted:    3.2K
 * Total Submissions: 5K
 * Testcase Example:  '1\n4\n0\n0'
 *
 * On a 2 dimensional grid with R rows and C columns, we start at (r0, c0)
 * facing east.
 *
 * Here, the north-west corner of the grid is at the first row and column, and
 * the south-east corner of the grid is at the last row and column.
 *
 * Now, we walk in a clockwise spiral shape to visit every position in this
 * grid. 
 *
 * Whenever we would move outside the boundary of the grid, we continue our
 * walk outside the grid (but may return to the grid boundary later.) 
 *
 * Eventually, we reach all R * C spaces of the grid.
 *
 * Return a list of coordinates representing the positions of the grid in the
 * order they were visited.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: R = 1, C = 4, r0 = 0, c0 = 0
 * Output: [[0,0],[0,1],[0,2],[0,3]]
 *
 *
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: R = 5, C = 6, r0 = 1, c0 = 4
 * Output:
 * [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 *
 *
 *
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= R <= 100
 * 1 <= C <= 100
 * 0 <= r0 < R
 * 0 <= c0 < C
 *
 *
 *
 *
 */
class Solution {
public:
    // **Intuition**:
    // Take steps one by one.
    // If the location is inside of grid, add it to `res`.
    // But how to simulate the path?

    // It seems to be annoying, but if we oberserve the path:

    // move right `1` step, turn right
    // move down `1` step, turn right
    // move left `2` steps, turn right
    // move top `2` steps, turn right,
    // move right `3` steps, turn right
    // move down `3` steps, turn right
    // move left `4` steps, turn right
    // move top `4` steps, turn right,

    // we can find the sequence of steps: 1,1,2,2,3,3,4,4,5,5....

    // So there are two thing to figure out:
    // 1. how to generate sequence 1,1,2,2,3,3,4,4,5,5
    // 2. how to turn right?

    // **Generate sequence 1,1,2,2,3,3,4,4,5,5**
    // Let `n` be index of this sequence.
    // Then `A0 = 1`, `A1 = 1`, `A2 = 2` ......
    // We can include that `An = n / 2 + 1`

    // **How to turn right?**
    // By cross product:
    // Assume current direction is (x, y) in plane, which is (x, y, 0) in space.
    // Then the direction after turn right (x, y, 0) \xD7 (0, 0, 1) = (y, -x, 0)
    // Translate to code: `tmp = x; x = y; y = -tmp;`

    // By arrays of arrays:
    // The directions order is (0,1),(1,0),(0,-1),(-1,0), then repeat.
    // Just define a variable.

    // **Time Complexity**:
    // O(max(M,N) ^ 2)
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        vector<vector<int>> res = { { r, c } };
        res.reserve(R * C);
        int x = 0, y = 1, tmp;
        for (int n = 0; res.size() < R * C; n++) {
            for (int i = 0; i < n / 2 + 1; i++) {
                r += x, c += y;
                if (0 <= r && r < R && 0 <= c && c < C)
                    res.push_back({ r, c });
            }
            tmp = x, x = y, y = -tmp;
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }


int mymain(int argc, char* argv[]) { return 0; }
