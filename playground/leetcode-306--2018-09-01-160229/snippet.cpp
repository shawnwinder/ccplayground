// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (27.87%)
 * Total Accepted:    34.1K
 * Total Submissions: 122.3K
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 *
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Example 1:
 *
 *
 * Input: "112358"
 * Output: true
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5,
 * 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 *
 * Example 2:
 *
 *
 * Input: "199100199"
 * Output: true
 * Explanation: The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 */
class Solution {
public:
    int check(string& s, int i, string&& t) {
        int j = 0;
        while (i < s.size() && j < t.size() && s[i] == t[j]) {
            i++, j++;
        }
        if (j < t.size()) return -1; else return i;
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if (len < 3) return false;
        for (int i=0;i< (num[0] == '0'? 1 : min(len/2+1, 10));i++) {
            long a = stol(num.substr(0, i+1));
            for (int j=i+1;j< (num[i+1] == '0'? i+2 : i+1+min(len/2+1, 10));j++) {
                long b = stol(num.substr(i+1, j - i));
                int f = j+1;
                long aa = a;
                while (true) {
                    long c = a + b;
                    int k = check(num, f, to_string(c));
                    if (k == -1) break;
                    else if (k == num.size()) return true;
                    a = b;
                    b = c;
                    f = k;
                }
                a = aa;
            }
        }
        return false;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
