// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (28.05%)
 * Total Accepted:    164.8K
 * Total Submissions: 587.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 *  [1, 2, 3, 4],
 *  [5, 6, 7, 8],
 *  [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        if (matrix.empty() || matrix[0].empty())
            return r;
        int m = matrix.size(), n = matrix[0].size();
        int c = 1;
        for (int i = 0; i < (min(m, n) + 1) / 2; i++) {
            for (int j = i; j < n - i; j++)
                r.push_back(matrix[i][j]);
            for (int j = i + 1; j < m - i; j++)
                r.push_back(matrix[j][n - 1 - i]);
            if (i < m / 2)
                for (int j = n - 2 - i; j >= i; j--)
                    r.push_back(matrix[m - 1 - i][j]);
            if (i < n / 2)
                for (int j = m - 2 - i; j >= i + 1; j--)
                    r.push_back(matrix[j][i]);
        }
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
