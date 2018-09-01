// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * [807] Custom Sort String
 *
 * https://leetcode.com/problems/custom-sort-string/description/
 *
 * algorithms
 * Medium (59.59%)
 * Total Accepted:    15.7K
 * Total Submissions: 26.4K
 * Testcase Example:  '"cba"\n"abcd"'
 *
 * S and T are strings composed of lowercase letters. In S, no letter occurs
 * more than once.
 *
 * S was sorted in some custom order previously. We want to permute the
 * characters of T so that they match the order that S was sorted. More
 * specifically, if x occurs before y in S, then x should occur before y in the
 * returned string.
 *
 * Return any permutation of T (as a string) that satisfies this property.
 *
 *
 * Example :
 * Input:
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation:
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b",
 * and "a".
 * Since "d" does not appear in S, it can be at any position in T. "dcba",
 * "cdba", "cbda" are also valid outputs.
 *
 *
 *
 *
 * Note:
 *
 *
 * S has length at most 26, and no character is repeated in S.
 * T has length at most 200.
 * S and T consist of lowercase letters only.
 *
 *
 */
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> dir;
        int i = 0;
        transform(S.begin(), S.end(), inserter(dir, dir.end()),
            [&](char& a) { return make_pair(a, ++i); });
        sort(T.begin(), T.end(), [&](char a, char b) { return dir[a] < dir[b]; });
        return T;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
