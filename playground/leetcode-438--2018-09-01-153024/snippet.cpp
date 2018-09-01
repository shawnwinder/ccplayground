// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (34.21%)
 * Total Accepted:    76.3K
 * Total Submissions: 223.1K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 */
 class Solution {
 public:
   vector<int> findAnagrams(string s, string p) {
     int i = 0;
     int j = 0;
     int n = s.size();
     vector<int> ret;
     unordered_map<char, int> m;
     unordered_map<char, int> valid;
     for (char c : p) valid[c] ++;
     while (j < n) {
       if (valid[s[j]] == 0) {
         j ++;
         i = j;
         m.clear();
       } else {
         // validation
         while (m[s[j]] == valid[s[j]]) {
           m[s[i++]] --;
         }
                    m[s[j++]] ++;

         if ( j - i == p.size()) ret.push_back(i);
       }
     }
     return ret;
   }
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
