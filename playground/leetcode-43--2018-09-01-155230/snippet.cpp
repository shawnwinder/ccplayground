// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (28.55%)
 * Total Accepted:    153K
 * Total Submissions: 535.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 *
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 *
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Note:
 *
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
    string multiply(string a, string b) {
        vector<int> r(a.size() + b.size(), 0);
        int m = a.size(), n = b.size();
        for (int i = 0; i < m; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                r[i + j] += (a[m - 1 - i] - '0') * (b[n - 1 - j] - '0') + c;
                c = r[i + j] / 10;
                r[i + j] %= 10;
            }
            if (c)
                r[i + n] += c;
        }
        while (r.size() > 1 && !r.back())
            r.pop_back();
        string rr;
        for (auto it = r.rbegin(); it != r.rend(); ++it)
            rr += '0' + *it;
        return rr;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
