// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [906] Walking Robot Simulation
 *
 * https://leetcode.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (27.99%)
 * Total Accepted:    3.8K
 * Total Submissions: 13.6K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * A robot on an infinite grid starts at point (0, 0) and faces north.  The
 * robot can receive one of three possible types of commands:
 *
 *
 * -2: turn left 90 degrees
 * -1: turn right 90 degrees
 * 1 <= x <= 9: move forward x units
 *
 *
 * Some of the grid squares are obstacles. 
 *
 * The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
 *
 * If the robot would try to move onto them, the robot stays on the previous
 * grid square instead (but still continues following the rest of the route.)
 *
 * Return the square of the maximum Euclidean distance that the robot will be
 * from the origin.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: commands = [4,-1,3], obstacles = []
 * Output: 25
 * Explanation: robot will go to (3, 4)
 *
 *
 *
 * Example 2:
 *
 *
 * Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * Output: 65
 * Explanation: robot will be stuck at (1, 4) before turning left and going to
 * (1, 8)
 *
 *
 * Note:
 *
 *
 * 0 <= commands.length <= 10000
 * 0 <= obstacles.length <= 10000
 * -30000 <= obstacle[i][0] <= 30000
 * -30000 <= obstacle[i][1] <= 30000
 * The answer is guaranteed to be less than 2 ^ 31.
 *
 */
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (int i = 0; i < obstacles.size(); i++)
            obs.insert(to_string(obstacles[i][0]) + "#" + to_string(obstacles[i][1]));
        int res = 0, dir = 0, x = 0, y = 0;
        vector<vector<int>> ds = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2)
                dir--;
            else if (commands[i] == -1)
                dir++;
            else {
                for (int j = 0; j < commands[i]; j++) {
                    string pos = to_string(x + ds[dir][0]) + "#" + to_string(y + ds[dir][1]);
                    if (obs.find(pos) != obs.end())
                        break;
                    x += ds[dir][0], y += ds[dir][1];
                }
                res = max(res, x * x + y * y);
            }
            if (dir == -1)
                dir = 3;
            if (dir == 4)
                dir = 0;
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }


int mymain(int argc, char* argv[]) { return 0; }
