// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.80%)
 * Total Accepted:    121.2K
 * Total Submissions: 304.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 * Example 1:
 *
 *
 * Input: "hello"
 * Output: "holle"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "leetcode"
 * Output: "leotcede"
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 *
 *
 */
class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() -1;
        unordered_set<char> m = {'a', 'e', 'i', 'o', 'u'};
        while (l < r) {
            while (l<r && !m.count(tolower(s[l]))) l++;
            while (l<r && !m.count(tolower(s[r]))) r--;
            if (l<r) swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
        
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
