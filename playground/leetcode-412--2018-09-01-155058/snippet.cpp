// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.02%)
 * Total Accepted:    138.8K
 * Total Submissions: 239.3K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 *
 * Example:
 *
 * n = 15,
 *
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 *
 *
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i=1; i <= n; i++) {
            stringstream ss;
            if (i % 3 == 0) {
                ss << "Fizz";
            }
            if (i % 5 == 0) {
                ss << "Buzz";
            }
            if (ss.rdbuf()->in_avail() == 0 ) {
                ss << i;
            }
            ans.push_back(ss.str());
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
