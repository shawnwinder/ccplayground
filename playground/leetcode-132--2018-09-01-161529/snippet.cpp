// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (25.55%)
 * Total Accepted:    87.4K
 * Total Submissions: 342.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 *
 *
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1)
            return 0;
        vector<int> mincuts(n + 1);
        for (int i = 0; i <= n; ++i)
            mincuts[i] = i - 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; (i - j) >= 0 && (i + j) < n && s[i - j] == s[i + j]; ++j)
                mincuts[i + j + 1] = min(mincuts[i + j + 1], 1 + mincuts[i - j]);
            for (int j = 0; (i - j - 1) >= 0 && (i + j) < n && s[i - j - 1] == s[i + j]; ++j)
                mincuts[i + j + 1] = min(mincuts[i + j + 1], 1 + mincuts[i - j - 1]);
        }
        return mincuts[n];
    }
};

int mymain(int argc, char* argv[]) { return 0; }
