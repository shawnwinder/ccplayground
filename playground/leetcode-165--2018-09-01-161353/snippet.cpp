// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (21.42%)
 * Total Accepted:    109K
 * Total Submissions: 508.8K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise
 * return 0.
 *
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 *
 * Example 1:
 *
 *
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 *
 * Example 2:
 *
 *
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 *
 * Example 3:
 *
 *
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 *
 */
 class Solution {
 public:
   vector<int> parse(string& v) {
     stringstream ss(v);
     int i;
     char sep;
     vector<int> ret;
     while (true) {
       ss >> i;
       ret.push_back(i);
       if (! (ss >> sep)) break;
     }
     return ret;
   }

   int compareVersion(string version1, string version2) {
     vector<int> l = parse(version1);
     vector<int> r = parse(version2);
     int i;
     for (i = 0;  i < min(l.size(), r.size()); i++ ) {
       if (l[i] < r[i]) return -1;
       if (l[i] > r[i]) return 1;
     }
     while (i < l.size()) {
       if(l[i] > 0) return 1;
       i ++;
     }
     while (i < r.size()) {
       if(r[i] > 0) return -1;
       i ++;
     }
     return 0;
   }
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
