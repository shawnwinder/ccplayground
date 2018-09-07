// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (34.89%)
 * Total Accepted:    22.8K
 * Total Submissions: 65.4K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is
 * an extremely large positive integer given in the form of an array.
 *
 * Example 1:
 *
 *
 *
 * Input: a = 2, b = [3]
 * Output: 8
 *
 *
 *
 * Example 2:
 *
 *
 * Input: a = 2, b = [1,0]
 * Output: 1024
 *
 *
 *
 *
 */
class Solution {
public:
    // Euler's totient
    int superPow(int a, vector<int>& b) {
        int c = 0, x = 1;
        for (int x : b)
            c = (c * 10 + x) % ((7 - 1) * (191 - 1));
        a %= 1337;
        while (c--)
            x = x * a % 1337;
        return x;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
