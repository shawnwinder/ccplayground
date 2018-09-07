// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (44.49%)
 * Total Accepted:    25.7K
 * Total Submissions: 57.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 *
 *
 * Example:
 *
 * Input:
 * [
 * [ 1, 2, 3 ],
 * [ 4, 5, 6 ],
 * [ 7, 8, 9 ]
 * ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 * Explanation:
 *
 *
 *
 *
 * Note:
 *
 * The total number of elements of the given matrix will not exceed 10,000.
 *
 *
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int d = 1;
        int i = 0, j = 0;
        if (matrix.empty())
            return ret;
        int x = matrix.size() - 1, y = matrix[0].size() - 1;
        while (true) {
            if (i >= 0 && j >= 0 && i <= x && j <= y)
                ret.push_back(matrix[i][j]);
            if (i == x && j == y) {
                break;
            } else if (i == x && d == -1) {
                j++;
                d = 1;
            } else if (i == 0 && d == 1) {
                j++;
                d = -1;
            } else if (j == 0 && d == -1) {
                i++;
                d = 1;
            } else if (j == y && d == 1) {
                i++;
                d = -1;
            } else if (d == 1) {
                i--;
                j++;
            } else if (d == -1) {
                i++;
                j--;
            }
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
