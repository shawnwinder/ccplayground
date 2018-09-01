// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (30.21%)
 * Total Accepted:    78.4K
 * Total Submissions: 259.6K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 *
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 *
 *
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 *
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 *
 *
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 *
 *
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 *
 *
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 *
 *
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 *
 * Example 1:
 *
 *
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 *
 */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        bool ret = true;
        size_t n = s1.length();
        if (n > 0) // if s1 is empty, return true
        {
            // Dynamic Programming: 
            // eq[first1][first2][len] == true iff s1[first1 ... first1+len) == s2[first2 ... first2+len)
            vector<vector<vector<bool> > > eq
                (n, vector<vector<bool>>(n, vector<bool>(n + 1, false))); // initialize: all false

            // initialize: eq[first1][first2][1] = true iff s1[first1] == s2[first2]
            for (int first1 = 0; first1 < n; ++first1)
            {
                for (int first2 = 0; first2 < n; ++first2)
                {
                    eq[first1][first2][1] = (s1[first1] == s2[first2]);
                }
            }

            // dp: eq[first1][first2][len] = true iff two substrings are both matched.
            for (size_t len = 2; len <= n; ++len)
            {
                for (size_t first1 = 0; first1 + len <= n; ++first1)
                {
                    for (size_t first2 = 0; first2 + len <= n; ++first2)
                    {
                        for (size_t len1 = 1; len1 < len; ++len1)
                        {
                            size_t len2 = len - len1;

                            // two substrings are not swapped
                            if (eq[first1][first2][len1] && eq[first1 + len1][first2 + len1][len2])
                            {
                                eq[first1][first2][len] = true;
                            }

                            // two substrings are swapped
                            if (eq[first1][first2 + len2][len1] && eq[first1 + len1][first2][len2])
                            {
                                eq[first1][first2][len] = true;
                            }
                        }
                    }
                }
            }
            ret = eq[0][0][n];
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
