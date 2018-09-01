// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

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
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int k = 1, i = 0;
        while (k <= n * n) {
            int j = i;
            // four steps
            while (j < n - i) // 1. horizonal, left to right
                ret[i][j++] = k++;
            j = i + 1;
            while (j < n - i) // 2. vertical, top to bottom
                ret[j++][n - i - 1] = k++;
            j = n - i - 2;
            while (j > i) // 3. horizonal, right to left
                ret[n - i - 1][j--] = k++;
            j = n - i - 1;
            while (j > i) // 4. vertical, bottom to  top
                ret[j--][i] = k++;
            i++; // next loop
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
