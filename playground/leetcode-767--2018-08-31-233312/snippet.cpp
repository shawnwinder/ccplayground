// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * [778] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (37.70%)
 * Total Accepted:    10.1K
 * Total Submissions: 26.8K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 *
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 *
 * Example 1:
 *
 *
 * Input: S = "aab"
 * Output: "aba"
 *
 *
 * Example 2:
 *
 *
 * Input: S = "aaab"
 * Output: ""
 *
 *
 * Note:
 *
 *
 * S will consist of lowercase letters and have length in range [1, 500].
 *
 *
 *
 */
class Solution {
public:
    // The solution sort the string by occurrence, i.e. the character with most
    // occurrence is at front. For example, aaaaabbcc. Next, let i = 0 at the
    // beginning, j = (n-1)/2+1 in the middle. We can build the answer by appending
    // s[i++] and s[j++] sequentially.
    string reorganizeString(string S) {
        size_t n = S.size();
        size_t m = 0;
        char mc = 0;
        unordered_map<char, int> cnt;
        for (auto i = 0u; i < S.size(); ++i) {
            int x = ++cnt[S[i]];
            if (x > m) {
                m = x;
                mc = S[i];
            }
        }
        if (m > (n + 1) / 2)
            return "";
        std::sort(std::begin(S), std::end(S), [&](char a, char b) { return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b); });
        string ans;
        for (int i = 0, j = (n - 1) / 2 + 1; i <= (n - 1) / 2; ++i, ++j) {
            ans += S[i];
            if (j < n)
                ans += S[j];
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }


int mymain(int argc, char* argv[]) { return 0; }
