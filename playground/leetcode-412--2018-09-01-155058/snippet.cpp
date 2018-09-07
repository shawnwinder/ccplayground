// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <sstream>
#include <vector>

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
 * But for multiples of three it should output "Fizz" instead of the number and
 * for the multiples of five output "Buzz". For numbers which are multiples of
 * both three and five output "FizzBuzz".
 *
 * Example:
 *
 * n = 15,
 *
 * Return:
 * [
 *    "1",
 *    "2",
 *    "Fizz",
 *    "4",
 *    "Buzz",
 *    "Fizz",
 *    "7",
 *    "8",
 *    "Fizz",
 *    "Buzz",
 *    "11",
 *    "Fizz",
 *    "13",
 *    "14",
 *    "FizzBuzz"
 * ]
 *
 *
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int fizz = 3, buzz = 5, fizzbuzz = 15;
        vector<string> r;
        for (int i = 1; i <= n; i++)
            if (i == fizzbuzz)
                r.push_back("FizzBuzz"), fizz += 3, buzz += 5, fizzbuzz += 15;
            else if (i == fizz)
                r.push_back("Fizz"), fizz += 3;
            else if (i == buzz)
                r.push_back("Buzz"), buzz += 5;
            else
                r.push_back(to_string(i));
        return r;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
