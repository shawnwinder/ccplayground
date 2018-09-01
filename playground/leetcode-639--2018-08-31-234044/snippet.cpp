// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (24.20%)
 * Total Accepted:    15.2K
 * Total Submissions: 63K
 * Testcase Example:  '"*"'
 *
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 *
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 *
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 *
 *
 *
 *
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 *
 *
 *
 * Also, since the answer may be very large, you should return the output mod
 * 109 + 7.
 *
 *
 * Example 1:
 *
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 *
 *
 *
 * Example 2:
 *
 * Input: "1*"
 * Output: 9 + 9 = 18
 *
 *
 *
 * Note:
 *
 * The length of the input string will fit in range [1, 105].
 * The input string will only contain the character '*' and digits '0' - '9'.
 *
 *
 */
class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string, int> m;
        for (int i=1;i<10;i++) {
            m[to_string(i)] = true;
            m["1" + to_string(i)] = true;
        }
        m["10"] = true;
        for (int i=0;i<7;i++) {
            m["2" + to_string(i)] = true;
        }
        m["*"] = 9;
        m["**"] = 15;
        m["1*"] = 9;
        m["2*"] = 6;
        m["*0"] = 2;
        for (int i=0;i<7;i++) {
            m["*" + to_string(i)] = 2;
        }
        m["*7"] = 1;
        m["*8"] = 1;
        m["*9"] = 1;
        long MOD = 1e9+7;
        vector<long> dp(s.size()+1, 0);
        dp[1] = m[s.substr(0, 1)];
        dp[0] = 1;
        for (int i = 2;i <=s.size(); i++) {
            dp[i] = (m[s.substr(i-1, 1)] * dp[i-1] + m[s.substr(i-2, 2)]*dp[i-2] ) % MOD;
        }
        return dp[s.size()];
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
