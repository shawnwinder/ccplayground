// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (41.20%)
 * Total Accepted:    38K
 * Total Submissions: 92.3K
 * Testcase Example:  '26'
 *
 *
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 *
 *
 * Note:
 *
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 26
 *
 * Output:
 * "1a"
 *
 *
 *
 * Example 2:
 *
 * Input:
 * -1
 *
 * Output:
 * "ffffffff"
 *
 *
 */

const static string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }
        return result;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
