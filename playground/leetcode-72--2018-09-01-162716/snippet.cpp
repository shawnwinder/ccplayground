// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (33.92%)
 * Total Accepted:    130.1K
 * Total Submissions: 383.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 */
class Solution {
public:
  int minDistance(string a, string b) {
    if (a.size() < b.size())
      swap(a, b);
    vector<int> d(b.size()+1);
    iota(d.begin(), d.end(), 0);
    for(int i=0;i<a.size();i++) {
      int ul = d[0];
      d[0] = i+1;
      for(int j=0;j<b.size();j++) {
        int t = d[j+1];
        d[j+1] = a[i] == b[j] ? ul : min(ul, min(d[j], d[j+1])) + 1;
        ul = t;
      }
    }
    return d.back();
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
