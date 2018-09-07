// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

/*
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (28.96%)
 * Total Accepted:    16.9K
 * Total Submissions: 58.2K
 * Testcase Example:  '12'
 *
 * Given a positive 32-bit integer n, you need to find the smallest 32-bit
 * integer which has exactly the same digits existing in the integer n and is
 * greater in value than n. If no such positive 32-bit integer exists, you need
 * to return -1.
 *
 * Example 1:
 *
 *
 * Input: 12
 * Output: 21
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 21
 * Output: -1
 *
 *
 *
 *
 */
class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
