// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <cmath>
#include <iostream>

using namespace std;

/*
 * [900] Reordered Power of 2
 *
 * https://leetcode.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (47.69%)
 * Total Accepted:    4.8K
 * Total Submissions: 10K
 * Testcase Example:  '1'
 *
 * Starting with a positive integer N, we reorder the digits in any order
 * (including the original order) such that the leading digit is not zero.
 *
 * Return true if and only if we can do this in a way such that the resulting
 * number is a power of 2.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 10
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: 16
 * Output: true
 *
 *
 *
 * Example 4:
 *
 *
 * Input: 24
 * Output: false
 *
 *
 *
 * Example 5:
 *
 *
 * Input: 46
 * Output: true
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 10^9
 */
class Solution {
public:
    // `counter` will counter the number of digits 9876543210 in the given number.
    // Then I just compare `counter(N)` with all `counter(power of 2)`.
    // `1 <= N <= 10^9`, so up to 8 same digits.
    // If N > 10^9, we can use a hash map.
    bool reorderedPowerOf2(int N) {
        long c = counter(N);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c)
                return true;
        return false;
    }
    long counter(int N) {
        long res = 0;
        for (; N; N /= 10)
            res += pow(10, N % 10);
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
