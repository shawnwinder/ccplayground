// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (36.73%)
 * Total Accepted:    52.5K
 * Total Submissions: 143K
 * Testcase Example:  '5'
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * 
 * Given n, find the total number of full staircase rows that can be formed.
 *
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 *
 * Example 1:
 *
 * n = 5
 *
 * The coins can form the following rows:
 * ?
 * ? ?
 * ? ?
 *
 * Because the 3rd row is incomplete, we return 2.
 *
 *
 *
 * Example 2:
 *
 * n = 8
 *
 * The coins can form the following rows:
 * ?
 * ? ?
 * ? ? ?
 * ? ?
 *
 * Because the 4th row is incomplete, we return 3.
 *
 *
 */
class Solution {
public:
    int arrangeCoins(int n) {
        double root = (-1 + sqrt(1.0 + 8.0 * n)) / 2;
        return floor(root);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
