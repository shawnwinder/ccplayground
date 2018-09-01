// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (51.90%)
 * Total Accepted:    66.3K
 * Total Submissions: 127.8K
 * Testcase Example:  '"USA"'
 *
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 *
 *
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 *
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 *
 *
 * Example 1:
 *
 * Input: "USA"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "FlaG"
 * Output: False
 *
 *
 *
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 *
 */
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) return true;
        bool first = isupper(word[0]);
        bool lower = true;
        bool upper = true;
        for (int i = 1; i < word.size() ; i ++) {
            lower &= islower(word[i]) != 0;
            upper &= isupper(word[i]) != 0;
        }
        return (first && upper) || (lower);
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
