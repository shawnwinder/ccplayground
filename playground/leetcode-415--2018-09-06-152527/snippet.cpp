// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (41.99%)
 * Total Accepted:    66K
 * Total Submissions: 157.3K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        for (int i = num1.size() - 1, j = num2.size() - 1, carry = 0; i >= 0 || j >= 0 || carry;
             carry /= 10) {
            if (i >= 0)
                carry += num1[i--] - '0';
            if (j >= 0)
                carry += num2[j--] - '0';
            result = to_string(carry % 10) + result;
        }
        return result;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
