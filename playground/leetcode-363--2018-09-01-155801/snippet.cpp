// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (34.08%)
 * Total Accepted:    21.7K
 * Total Submissions: 63.7K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 *
 * Example:
 *
 *
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is
 * 2,
 * and 2 is the max number no larger than k (k = 2).
 *
 * Note:
 *
 *
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 *
 *
 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        if (row > col) {
            vector<vector<int>> a(col, vector<int>(row));
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    a[j][i] = matrix[i][j];
                }
            }
            matrix = a;
            swap(row, col);
        }
        int ans = INT_MIN;
        for (int i = 0; i < row; i++) {
            vector<int> vs(col, 0);
            for (int j = i; j < row; j++) {
                set<int> cum;
                cum.insert(0);
                int agg = 0;
                for (int l = 0; l < col; l++) {
                    agg += vs[l] += matrix[j][l];
                    auto f = cum.lower_bound(agg - k);
                    if (f != cum.end())
                        ans = max(ans, agg - *f);
                    cum.insert(agg);
                }
            }
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
