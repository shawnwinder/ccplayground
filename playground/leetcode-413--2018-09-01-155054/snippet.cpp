// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (54.49%)
 * Total Accepted:    45.8K
 * Total Submissions: 84.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 *
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 *
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7
 *
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0
 *
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 *    A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 *
 * The function should return the number of arithmetic slices in the array
 * A.
 *
 *
 * Example:
 *
 * A = [1, 2, 3, 4]
 *
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 *
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> ans;
        if (A.size() < 3) return 0;
        int d = A[1] - A[0];
        int cnt = 2;
        for (int e = 2; e < A.size(); e ++) {
            if (A[e] - A[e - 1] == d) {
                cnt ++;
            } else {
                ans.push_back(cnt);
                d = A[e] - A[e - 1];
                cnt = 2;
            }
        }
        ans.push_back(cnt);
        int ret = 0;
        for (int x : ans) {
            if ( x >= 3) {
                ret += (x - 2) * (x - 1) / 2;
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
