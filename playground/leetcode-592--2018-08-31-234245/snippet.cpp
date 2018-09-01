// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [592] Fraction Addition and Subtraction
 *
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (46.20%)
 * Total Accepted:    9.7K
 * Total Submissions: 21.1K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * Given a string representing an expression of fraction addition and
 * subtraction, you need to return the calculation result in string format. The
 * final result should be irreducible fraction. If your final result is an
 * integer, say 2, you need to change it to the format of fraction that has
 * denominator 1. So in this case, 2 should be converted to 2/1.
 *
 * Example 1:
 *
 * Input:"-1/2+1/2"
 * Output: "0/1"
 *
 *
 *
 * Example 2:
 *
 * Input:"-1/2+1/2+1/3"
 * Output: "1/3"
 *
 *
 *
 * Example 3:
 *
 * Input:"1/3-1/2"
 * Output: "-1/6"
 *
 *
 *
 * Example 4:
 *
 * Input:"5/3+1/3"
 * Output: "2/1"
 *
 *
 *
 * Note:
 *
 * The input string only contains '0' to '9', '/', '+' and '-'. So does the
 * output.
 * Each fraction (input and output) has format ±numerator/denominator. If the
 * first input fraction or the output is positive, then '+' will be omitted.
 * The input only contains valid irreducible fractions, where the numerator and
 * denominator of each fraction will always be in the range [1,10]. If the
 * denominator is 1, it means this fraction is actually an integer in a
 * fraction format defined above.
 * The number of given fractions will be in the range [1,10].
 * The numerator and denominator of the final result are guaranteed to be valid
 * and in the range of 32-bit int.
 *
 *
 */
class Solution {
public:
    using pp=pair<int, int>;
    int gcd(int a, int b){ return (b == 0) ? a : gcd(b, a % b); }

    string fractionAddition(string expression) {
        vector<char> ops;

        vector<pp> nums;
        istringstream is(expression);
        while(true) {
            char c;
            int a, b;
            is >> a >> c >> b;
            nums.emplace_back(a, b);
            if (is >> c) {
                ops.push_back(c);
            } else {
                break;
            }
        }
        pp cd = accumulate(nums.begin(), nums.end(), pp(1, 1), [&](pp& a, pp& b) {
            return pp(1, a.second * b.second / gcd(a.second, b.second));
        });
        nums[0].first *= cd.second / nums[0].second;
        int i = 0;
        pp ret = accumulate(nums.begin() + 1, nums.end(), nums[0], [&](pp& a, pp& b) {
            if (ops[i++] == '+') {
              return pp{a.first + b.first * (cd.second / b.second), cd.second};
            } else {
              return pp{a.first - b.first * (cd.second / b.second), cd.second};
            }
        });
        int f = abs(gcd(ret.first, ret.second));
        ostringstream os;
        os << ret.first / f<< '/' << (ret.first?ret.second / f:1);
        return os.str();
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
