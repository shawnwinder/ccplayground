// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (58.41%)
 * Total Accepted:    95.3K
 * Total Submissions: 163.1K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 *
 * Example:
 *
 * [[0,1,0,0],
 * [1,1,1,0],
 * [0,1,0,0],
 * [1,1,0,0]]
 *
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 *
 *
 *
 */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0 ; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 0) continue;
                if (i == 0) ans ++;
                else if (grid[i-1][j] == 0) ans ++;
                
                if (j == 0) ans ++;
                else if (grid[i][j-1] == 0) ans ++;
                
                if (i == grid.size() - 1) ans ++;
                else if (grid[i+1][j] == 0) ans ++;
                
                if (j == grid[0].size() - 1) ans ++;
                else if (grid[i][j+1] == 0) ans ++;
            }
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
