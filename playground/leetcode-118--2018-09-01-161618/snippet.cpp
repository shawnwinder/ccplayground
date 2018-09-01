// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (41.76%)
 * Total Accepted:    190.6K
 * Total Submissions: 456.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> ws;
        for (int i=0;i<numRows;i++) {
            vector<int> pend;
            int l = 0;
            for (int x : ws) {
                pend.push_back(x + l);
                l = x;
            }
            pend.push_back(1);
            ws = pend;
            ret.push_back(ws);
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
