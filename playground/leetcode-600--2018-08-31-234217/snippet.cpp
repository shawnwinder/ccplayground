// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [600] Non-negative Integers without Consecutive Ones
 *
 * https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
 *
 * algorithms
 * Hard (31.87%)
 * Total Accepted:    6.6K
 * Total Submissions: 20.8K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, find the number of non-negative integers less
 * than or equal to n, whose binary representations do NOT contain consecutive
 * ones.
 *
 * Example 1:
 *
 * Input: 5
 * Output: 5
 * Explanation:
 * Here are the non-negative integers
 *
 *
 * Note:
 * 1 9
 *
 *
 */
class Solution {
public:
    int findIntegers(int num) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < f.size(); i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    sum--;
                    break;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
