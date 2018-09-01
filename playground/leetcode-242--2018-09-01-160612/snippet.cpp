// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (48.65%)
 * Total Accepted:    241.3K
 * Total Submissions: 496K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        auto cnt = vector<int>(255, 0);
        for(auto c: s) {
            cnt[c] ++;
        }
        for(auto c: t) {
            cnt[c] --;
        }
        for(auto c: cnt) {
            if(c != 0) return false;
        }
        return true;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
