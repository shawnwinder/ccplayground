// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.53%)
 * Total Accepted:    157.1K
 * Total Submissions: 330.5K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> x(256, 0);
        for (auto c : s) {
            x[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (x[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
