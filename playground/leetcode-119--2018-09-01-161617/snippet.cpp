// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (39.66%)
 * Total Accepted:    159.5K
 * Total Submissions: 402.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k <= 33, return the kth index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> s(rowIndex + 1);
        s[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                s[j] += s[j - 1];
            }
            s[i] = 1;
        }
        return s;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
