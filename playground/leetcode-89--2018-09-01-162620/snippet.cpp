// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (43.46%)
 * Total Accepted:    114.8K
 * Total Submissions: 264K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 *
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 *
 *
 * Example 2:
 *
 *
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2n, which for n = 0 the size is 20 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 *
 *
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        deque<int> ret;
        if (n == 0) return {0};
        ret.push_back(0);
        ret.push_back(1);
        int i = 1;
        while (i < n) {
            int bit = log2(ret.back() & (-ret.back())) + 1;
            int x = 1 << bit;
            for (int j = ret.size() - 1; j >=0; j--) {
                ret.push_back(x + ret[j]);
            }
            i ++;
        }
        return vector<int>(ret.begin(), ret.end());
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
