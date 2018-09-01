// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [191] Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (40.80%)
 * Total Accepted:    212.7K
 * Total Submissions: 521.2K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Write a function that takes an unsigned integer and returns the number of
 * '1' bits it has (also known as the Hamming weight).
 *
 * Example 1:
 *
 *
 * Input: 11
 * Output: 3
 * Explanation: Integer 11 has binary representation
 * 00000000000000000000000000001011
 *
 *
 * Example 2:
 *
 *
 * Input: 128
 * Output: 1
 * Explanation: Integer 128 has binary representation
 * 00000000000000000000000010000000
 *
 *
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n = n ^ (n & (-n));
            cnt++;
        }
        return cnt;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
