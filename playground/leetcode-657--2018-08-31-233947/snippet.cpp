// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [657] Judge Route Circle
 *
 * https://leetcode.com/problems/judge-route-circle/description/
 *
 * algorithms
 * Easy (68.91%)
 * Total Accepted:    99.5K
 * Total Submissions: 144.3K
 * Testcase Example:  '"UD"'
 *
 * Initially, there is a Robot at position (0, 0). Given a sequence of its
 * moves, judge if this robot makes a circle, which means it moves back to the
 * original place.
 *
 * The move sequence is represented by a string. And each move is represent by
 * a character. The valid robot moves are R (Right), L (Left), U (Up) and D
 * (down). The output should be true or false representing whether the robot
 * makes a circle.
 *
 * Example 1:
 *
 *
 * Input: "UD"
 * Output: true
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "LL"
 * Output: false
 *
 *
 *
 *
 */
 class Solution {
 public:
   bool judgeCircle(string moves) {
     int x = 0;
     int y = 0;
     for (char c : moves) {
       if ( c == 'U') y ++;
       else if ( c == 'D') y --;
       else if (c == 'L') x --;
       else if (c == 'R') x ++;
     }
     return x == 0 && y == 0;
   }
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
