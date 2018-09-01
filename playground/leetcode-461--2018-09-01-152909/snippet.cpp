// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (69.55%)
 * Total Accepted:    180.2K
 * Total Submissions: 259.1K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 <= x, y < 231.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *       ?   ?
 *
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int bits = x ^ y;
        int cnt = 0;
        while (bits != 0) {
            bits = bits & (bits - 1);
            cnt ++;
        }
        return cnt;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
