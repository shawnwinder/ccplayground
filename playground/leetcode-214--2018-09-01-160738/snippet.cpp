// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (25.77%)
 * Total Accepted:    59.3K
 * Total Submissions: 230K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 *
 * Example 1:
 *
 *
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 *
 *
 * Example 2:
 *
 *
 * Input: "abcd"
 * Output: "dcbabcd"
 *
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(s.begin(), s.end());
        // orginal string + reverse string --> longest prefix
        rs += s;
        int n = rs.size();
        vector<int> z(n);
        int left = 0;
        int mostRight = 0;
        // z algorithm
        for (int i = 1; i < n; i++) {
            if (i <= mostRight) {
                z[i] = min(mostRight - i + 1, z[i - left]);
            }
            while (i + z[i] < n && rs[i + z[i]] == rs[z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > mostRight) {
                mostRight = i + z[i] - 1;
                left = i;
            }
        }
        for (auto i = n / 2; i < n; ++i) {
            if (i + z[i] >= n)
                return s.substr(0, i - n / 2) + rs.substr(0, n / 2);
        }
        return "";
    }
};

int mymain(int argc, char* argv[]) {
    Solution s;
    cout << s.shortestPalindrome("abcd");
    return 0;
}
