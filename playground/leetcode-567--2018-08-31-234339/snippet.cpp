// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (36.53%)
 * Total Accepted:    27.1K
 * Total Submissions: 74.1K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 *
 * Example 1:
 *
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 *
 * Example 2:
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 *
 *
 *
 * Note:
 *
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 *
 *
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int miss[256] = {}, missSum = s1.size();
        for (char c : s1)
            miss[c]++;
        vector<int> result;
        for (int i = 0; i < s2.size(); i++) {
            missSum -= miss[s2[i]]-- > 0;
            int start = i + 1 - s1.size();
            if (!missSum)
                return true;
            missSum += start >= 0 && ++miss[s2[start]] > 0;
        }
        return false;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
