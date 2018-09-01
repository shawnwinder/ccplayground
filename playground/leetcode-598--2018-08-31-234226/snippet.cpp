// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [598] Range Addition II
 *
 * https://leetcode.com/problems/range-addition-ii/description/
 *
 * algorithms
 * Easy (47.95%)
 * Total Accepted:    24K
 * Total Submissions: 50K
 * Testcase Example:  '3\n3\n[[2,2],[3,3]]'
 *
 * Given an m * n matrix M initialized with all 0's and several update
 * operations.
 * Operations are represented by a 2D array, and each operation is represented
 * by an array with two positive integers a and b, which means M[i][j] should
 * be added by one for all 0  and 0 .
 * You need to count and return the number of maximum integers in the matrix
 * after performing all the operations.
 *
 * Example 1:
 *
 * Input:
 * m = 3, n = 3
 * operations = [[2,2],[3,3]]
 * Output: 4
 * Explanation:
 * Initially, M =
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 *
 * After performing [2,2], M =
 * [[1, 1, 0],
 * ⁠[1, 1, 0],
 * ⁠[0, 0, 0]]
 *
 * After performing [3,3], M =
 * [[2, 2, 1],
 * ⁠[2, 2, 1],
 * ⁠[1, 1, 1]]
 *
 * So the maximum integer in M is 2, and there are four of it in M. So return
 * 4.
 *
 *
 *
 * Note:
 *
 * The range of m and n is [1,40000].
 * The range of a is [1,m], and the range of b is [1,n].
 * The range of operations size won't exceed 10,000.
 *
 *
 */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x=m, y=n;
        for (auto& op : ops) {
            if (op[0] < x) x = op[0];
            if (op[1] < y) y = op[1];
        }
        return x*y;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
