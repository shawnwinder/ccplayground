// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (18.45%)
 * Total Accepted:    71.2K
 * Total Submissions: 385.7K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 *
 * Example 1:
 *
 *
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 *
 *
 * Example 2:
 *
 *
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 *
 * Example 3:
 *
 *
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 *
 *
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        int sign = (numerator < 0) ^ (denominator < 0) ? -1 : 1;
        long nume = labs(numerator), deno = labs(denominator);
        long left = nume / deno;
        if (nume % deno == 0)
            return sign == 1 ? to_string(left) : "-" + to_string(left);
        long t = nume % deno;
        string ans = to_string(left) + ".";
        vector<long> right;
        unordered_map<long, size_t> m;
        size_t pos = ans.size();
        m[t] = pos;
        while (t != 0) {
            t *= 10;
            ans += ('0' + t / deno);
            t = t % deno;
            if (m.find(t) != m.end()) {
                ans.insert(m[t], 1, '(');
                ans += ')';
                break;
            }
            m[t] = ++pos;
        }
        return sign == 1 ? ans : "-" + ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
