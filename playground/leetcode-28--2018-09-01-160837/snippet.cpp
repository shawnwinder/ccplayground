// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (29.80%)
 * Total Accepted:    308.9K
 * Total Submissions: 1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        string s = needle + '\0' + haystack;
        int n = s.size();
        vector<int> z(n);
        int left = 0;
        int mostRight = 0;
        for (int i = 1; i < n; i++) {
            if (i <= mostRight) {
                z[i] = min(mostRight - i + 1, z[i - left]);
            }
            while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
                z[i]++;
            }
            if (z[i] >= needle.size())
                return i - needle.size() - 1;
            if (i + z[i] - 1 > mostRight) {
                mostRight = i + z[i] - 1;
                left = i;
            }
        }
        return -1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
