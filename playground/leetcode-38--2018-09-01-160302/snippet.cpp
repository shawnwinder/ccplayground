// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.72%)
 * Total Accepted:    215.6K
 * Total Submissions: 571.7K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 *
 *
 * Given an integer n, generate the nth term of the count-and-say sequence.
 *
 *
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 *
 *
 *
 * Example 2:
 *
 * Input: 4
 * Output: "1211"
 *
 *
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
