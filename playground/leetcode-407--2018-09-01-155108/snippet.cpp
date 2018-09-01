// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [407] Trapping Rain Water II
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (37.77%)
 * Total Accepted:    19.7K
 * Total Submissions: 52.2K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * Given an m x n matrix of positive integers representing the height of each
 * unit cell in a 2D elevation map, compute the volume of water it is able to
 * trap after raining.
 *
 *
 * Note:
 * Both m and n are less than 110. The height of each unit cell is greater than
 * 0 and is less than 20,000.
 *
 *
 * Example:
 *
 * Given the following 3x6 height map:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 *
 * Return 4.
 *
 *
 *
 *
 *
 * The above image represents the elevation map
 * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
 *
 *
 *
 *
 * After the rain, water is trapped between the blocks. The total volume of
 * water trapped is 4.
 *
 */
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size()==0) return 0;
        using pp = pair<int, int>;
        priority_queue<pp, vector<pp>, greater<pp>> q;
        int row = heightMap.size(), col = heightMap[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int ans = 0, bar = INT_MIN;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(!(i==0 || i==row-1 || j==0 || j==col-1)) continue;
                q.push(make_pair(heightMap[i][j], i*col+j));
                visited[i][j] = true;
            }
        }
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            auto val = q.top(); q.pop();
            int height = val.first, x = val.second/col, y = val.second%col;
            bar = max(bar, height); // raise the bar
            for(auto d: dir)
            {
                int x2 = x + d[0], y2 = y + d[1];
                if(x2>=row || x2<0 || y2<0 || y2>=col || visited[x2][y2]) continue;
                visited[x2][y2] = true;
                if(heightMap[x2][y2] < bar) ans += bar - heightMap[x2][y2];
                q.push(make_pair(heightMap[x2][y2], x2*col+y2));
            }
        }
        return ans;
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
