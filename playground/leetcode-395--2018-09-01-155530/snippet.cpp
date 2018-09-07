// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (36.13%)
 * Total Accepted:    30.6K
 * Total Submissions: 84.6K
 * Testcase Example:  '"aaabb"\n3'
 *
 *
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 *
 *
 * Example 1:
 *
 * Input:
 * s = "aaabb", k = 3
 *
 * Output:
 * 3
 *
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "ababbc", k = 2
 *
 * Output:
 * 5
 *
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 *
 *
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0 || k > s.size())
            return 0;
        if (k == 0)
            return s.size();
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        int idx = 0;
        while (idx < s.size() && m[s[idx]] >= k)
            idx++;
        if (idx == s.size())
            return s.size();
        int left = longestSubstring(s.substr(0, idx), k);
        int right = longestSubstring(s.substr(idx + 1), k);
        return max(left, right);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
