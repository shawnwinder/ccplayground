// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (27.93%)
 * Total Accepted:    167.7K
 * Total Submissions: 0.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        string ret;
        unordered_map<char, int> valid, m;
        for (char c : t)
            valid[c]++;
        int cnt = valid.size();
        while (j < s.size()) {
            char c = s[j];
            m[c]++;
            if (m[c] == valid[c]) {
                // first time equal
                cnt--;
                // shrink to invalid
                bool shrinked = false;
                while (cnt == 0) {
                    shrinked = true;
                    char ic = s[i];
                    m[ic]--;
                    if (m[ic] < valid[ic]) {
                        cnt++;
                    }
                    i++;
                }
                // update
                if (shrinked && j - i + 2 < ans) {
                    ans = j - i + 2;
                    ret = s.substr(i - 1, ans);
                }
            }
            // expand to valid
            j++;
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
