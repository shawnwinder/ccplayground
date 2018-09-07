// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (23.12%)
 * Total Accepted:    68.9K
 * Total Submissions: 298.1K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 2^31 - 1.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: "One Hundred Twenty Three"
 *
 *
 * Example 2:
 *
 *
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 *
 * Example 3:
 *
 *
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 *
 *
 * Example 4:
 *
 *
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 *
 *
 */
class Solution {
    static const char* const below_20[];
    static const char* const below_100[];
    static string int_string(int n) {
        if (n >= 1000000000)
            return int_string(n / 1000000000) + " Billion"
                + int_string(n - 1000000000 * (n / 1000000000));
        else if (n >= 1000000)
            return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if (n >= 1000)
            return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if (n >= 100)
            return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if (n >= 20)
            return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if (n >= 1)
            return string(" ") + below_20[n - 1];
        else
            return "";
    }

public:
    static string numberToWords(int n) {
        if (n == 0)
            return "Zero";
        else
            return int_string(n).substr(1);
    }
};

const char* const Solution::below_20[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen" };
const char* const Solution::below_100[]
    = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

int mymain(int argc, char* argv[]) {
    std::cout << Solution::numberToWords(123) << std::endl;

    return 0;
}
