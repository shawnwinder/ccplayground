// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

/*
 * [564] Find the Closest Palindrome
 *
 * https://leetcode.com/problems/find-the-closest-palindrome/description/
 *
 * algorithms
 * Hard (17.03%)
 * Total Accepted:    7.1K
 * Total Submissions: 41.9K
 * Testcase Example:  '"1"'
 *
 * Given an integer n, find the closest integer (not including itself), which
 * is a palindrome.
 *
 * The 'closest' is defined as absolute difference minimized between two
 * integers.
 *
 * Example 1:
 *
 * Input: "123"
 * Output: "121"
 *
 *
 *
 * Note:
 *
 * The input n is a positive integer represented by string, whose length will
 * not exceed 18.
 * If there is a tie, return the smaller one as answer.
 *
 *
 */
class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        candidates.insert(pow(10, l) + 1);
        candidates.insert(pow(10, l - 1) - 1);
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for (long i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n);
        candidates.erase(num);
        auto it = candidates.lower_bound(num);
        if (it == candidates.begin())
            return to_string(*it);
        return num - *prev(it) <= *it - num ? to_string(*prev(it)) : to_string(*it);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
