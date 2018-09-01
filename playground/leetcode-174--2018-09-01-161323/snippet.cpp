// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (25.07%)
 * Total Accepted:    54K
 * Total Submissions: 215.6K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * table.dungeon, .dungeon th, .dungeon td {
 *  border:3px solid black;
 * }
 *
 * .dungeon th, .dungeon td {
 *    text-align: center;
 *    height: 70px;
 *    width: 70px;
 * }
 *
 * The demons had captured the princess (P) and imprisoned her in the
 * bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
 * out in a 2D grid. Our valiant knight (K) was initially positioned in the
 * top-left room and must fight his way through the dungeon to rescue the
 * princess.
 *
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately.
 *
 * Some of the rooms are guarded by demons, so the knight loses health
 * (negative integers) upon entering these rooms; other rooms are either empty
 * (0's) or contain magic orbs that increase the knight's health (positive
 * integers).
 *
 * In order to reach the princess as quickly as possible, the knight decides to
 * move only rightward or downward in each step.
 *
 *
 *
 * Write a function to determine the knight's minimum initial health so that he
 * is able to rescue the princess.
 *
 * For example, given the dungeon below, the initial health of the knight must
 * be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
 *
 *
 * -2 (K)
 * -3
 * 3
 *
 *
 * -5
 * -10
 * 1
 *
 *
 * 10
 * 30
 * -5 (P)
 *
 *
 * Note:
 *
 *
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight
 * enters and the bottom-right room where the princess is imprisoned.
 *
 *
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> dungeon) {
        vector<vector<int>> m(dungeon.size(), vector<int>(dungeon[0].size(), INT_MAX));
        m.back().back() = max(1, 1 - dungeon.back().back());
        for (int i = m.size() - 1; i >= 0; --i) {
            for (int j = m[i].size() - 1; j >= 0; --j) {
                if (i < m.size() - 1) {
                    m[i][j] = min(m[i][j], max(1, m[i + 1][j] - dungeon[i][j]));
                }
                if (j < m[i].size() - 1) {
                    m[i][j] = min(m[i][j], max(1, m[i][j + 1] - dungeon[i][j]));
                }
            }
        }
        return max(m[0][0], 1);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
