// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (42.71%)
 * Total Accepted:    110.7K
 * Total Submissions: 259.1K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 *
 * Example:
 *
 *
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int d = 1;
        vector<vector<int>> ret(n, vector<int>(n, 0));
        pair<int, int> cur = {0, 0};
        for (int i = 1;i<=n * n; i++) {
            ret[cur.second][cur.first] = i;
            switch (d) {
                case 1:
                    if (cur.first == n-1 || ret[cur.second][cur.first + 1]) {
                        d = 2;
                        cur.second ++;
                    } else cur.first ++;
                    break;
                case 2:
                    if (cur.second == n -1 || ret[cur.second + 1][cur.first]) {
                        d = 3;
                        cur.first --;
                    } else cur.second ++;
                    break;
                case 3:
                    if (cur.first == 0 || ret[cur.second][cur.first - 1]) {
                        d = 4;
                        cur.second --;
                    } else cur.first --;
                    break;
                case 4:
                    if (cur.second == 0 || ret[cur.second - 1][cur.first]) {
                        cur.first ++;
                        d = 1;
                    } else cur.second --;
                    break;
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
