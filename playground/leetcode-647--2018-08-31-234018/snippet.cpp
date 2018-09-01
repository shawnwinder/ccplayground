// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.45%)
 * Total Accepted:    55.5K
 * Total Submissions: 101.9K
 * Testcase Example:  '"abc"'
 *
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 *
 *
 *
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 *
 *
 * Example 1:
 *
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 *
 * Example 2:
 *
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Note:
 *
 * The input string length won't exceed 1000.
 *
 *
 */
class Solution {
public:
    int countSubstrings(string s) {
        // odd
        int ans = 0;
        
        for (int i=0;i<s.size();i++) {
            ans ++;
            int l=i-1;
            int r=i+1;
            while (l>=0 && r<s.size() && s[l--] == s[r++]) ans ++;
        }
        
        for (int i=0; i<s.size() -1;i++) {
            if (s[i] != s[i+1]) continue;
            ans ++;
            int l=i-1;
            int r=i+2;
            while (l >=0 && r<s.size() && s[l--] == s[r++]) ans ++;
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
