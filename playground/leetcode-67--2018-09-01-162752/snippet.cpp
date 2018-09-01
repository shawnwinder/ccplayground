// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.47%)
 * Total Accepted:    226.2K
 * Total Submissions: 637.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        stringstream ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        for (int i=0; i<a.size() || i<b.size(); i++) {
            int x = i<a.size() ? a[i] - '0' : 0;
            int y = i<b.size() ? b[i] - '0' : 0;
            int v = x + y + c;
            ret << (v == 1 || v == 3);
            c = (v>1);
        }
        if (c > 0) ret << c;
        string ans = ret.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
