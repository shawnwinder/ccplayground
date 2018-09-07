// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [466] Count The Repetitions
 *
 * https://leetcode.com/problems/count-the-repetitions/description/
 *
 * algorithms
 * Hard (27.24%)
 * Total Accepted:    6.5K
 * Total Submissions: 23.8K
 * Testcase Example:  '"acb"\n4\n"ab"\n2'
 *
 * Define S = [s,n] as the string S which consists of n connected strings s.
 * For example, ["abc", 3] ="abcabcabc".
 * On the other hand, we define that string s1 can be obtained from string s2
 * if we can remove some characters from s2 such that it becomes s1. For
 * example, "abc"  can be obtained from "abdbec" based on our definition, but
 * it can not be obtained from "acbbe".
 * You are given two non-empty strings s1 and s2 (each at most 100 characters
 * long) and two integers 0 <= n1 <= 106 and 1 <= n2 <= 106. Now consider the
 * strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer
 * M such that [S2,M] can be obtained from S1.
 *
 * Example:
 *
 * Input:
 * s1="acb", n1=4
 * s2="ab", n2=2
 *
 * Return:
 * 2
 *
 *
 */
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size(), c = 0, lo = -1, hi;
        vector<int> offset(l2 + 1, 0), cnt(l2 + 1);
        for (int i = 1, o = 0; i <= n1; i++) {
            for (int j = 0; j < l1; j++)
                if (s1[j] == s2[o] && ++o == l2) {
                    o = 0;
                    c++;
                }
            for (int j = 0; j < i; j++)
                if (o == offset[j]) {
                    lo = j;
                    hi = i;
                    goto out;
                }
            offset[i] = o;
            cnt[i] = c;
        }
    out:
        if (lo < 0)
            return c / n2;
        return ((n1 - lo) / (hi - lo) * (c - cnt[lo]) + cnt[lo + (n1 - lo) % (hi - lo)]) / n2;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
