// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (30.61%)
 * Total Accepted:    32.7K
 * Total Submissions: 106.8K
 * Testcase Example:  '8'
 *
 *
 * Given a positive integer n and you can do operations as follow:
 *
 *
 *
 *
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 *
 *
 *
 *
 * What is the minimum number of replacements needed for n to become 1?
 *
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 8
 *
 * Output:
 * 3
 *
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 *
 *
 *
 * Example 2:
 *
 * Input:
 * 7
 *
 * Output:
 * 4
 *
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 */
class Solution {
public:
    long integerReplacement(long n) {
        
        int div = 0;
        while (n % 2 == 0) n /= 2, div ++;
        if (n == 1) return div;
        else return div+1+ min(integerReplacement(n+1), integerReplacement(n-1));
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
