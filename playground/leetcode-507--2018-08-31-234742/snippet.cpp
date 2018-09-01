// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [507] Perfect Number
 *
 * https://leetcode.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (32.68%)
 * Total Accepted:    28.1K
 * Total Submissions: 85.9K
 * Testcase Example:  '28'
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself.
 *
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 *
 *
 * Example:
 *
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 *
 *
 *
 * Note:
 * The input number n will not exceed 100,000,000. (1e8)
 *
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        return sum - num == num;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
