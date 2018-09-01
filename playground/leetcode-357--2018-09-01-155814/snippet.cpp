// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (46.15%)
 * Total Accepted:    52.1K
 * Total Submissions: 112.8K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 *
 *
 * Example:
 *
 *
 * Input: 2
 * Output: 91
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100,
 * excluding 11,22,33,44,55,66,77,88,99
 *
 *
 *
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min ( 10, n);
        int ans = 1;
        for(int i=n-1;i>=0;i--) {
            int x = 9;
            for(int j=1;j<=i;j++) {
                x = x*(10-j);
            }
            ans += x;
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
