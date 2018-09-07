// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [522] Longest Uncommon Subsequence II
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (32.23%)
 * Total Accepted:    13.3K
 * Total Submissions: 41.2K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 *
 * Given a list of strings, you need to find the longest uncommon subsequence
 * among them. The longest uncommon subsequence is defined as the longest
 * subsequence of one of these strings and this subsequence should not be any
 * subsequence of the other strings.
 *
 *
 *
 * A subsequence is a sequence that can be derived from one sequence by
 * deleting some characters without changing the order of the remaining
 * elements. Trivially, any string is a subsequence of itself and an empty
 * string is a subsequence of any string.
 *
 *
 *
 * The input will be a list of strings, and the output needs to be the length
 * of the longest uncommon subsequence. If the longest uncommon subsequence
 * doesn't exist, return -1.
 *
 *
 * Example 1:
 *
 * Input: "aba", "cdc", "eae"
 * Output: 3
 *
 *
 *
 * Note:
 *
 * All the given strings' lengths will not exceed 10.
 * The length of the given list will be in the range of [2, 50].
 *
 *
 */
class Solution {
public:
    bool is_subseq(const string& l, const string& s) {
        int i = 0, j = 0;
        while (i < l.size() && j < s.size()) {
            if (l[i] == s[j])
                j++;
            i++;
        }
        return j == s.size();
    }
    int findLUSlength(vector<string>& strs) {
        if (strs.empty())
            return -1;
        unordered_map<string, int> m;
        for (auto& s : strs)
            m[s]++;
        vector<pair<string, int>> v(m.begin(), m.end());
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.first.size() > b.first.size();
        };
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++) {
            if (v[i].second == 1) {
                int j = 0;
                for (; j < i; j++) {
                    if (is_subseq(v[j].first, v[i].first))
                        break;
                }
                if (j == i)
                    return v[i].first.size();
            }
        }
        return -1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
