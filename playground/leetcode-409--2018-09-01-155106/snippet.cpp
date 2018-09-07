// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (46.37%)
 * Total Accepted:    73.1K
 * Total Submissions: 157.6K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> set(256, 0);
        for (auto c : s) {
            set[c]++;
        }
        int res = 0;
        for (int n : set) {
            res += n & 1 ? (res & 1 ? n - 1 : n) : n;
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
