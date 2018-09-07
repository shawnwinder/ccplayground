// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (46.55%)
 * Total Accepted:    68K
 * Total Submissions: 146K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 *
 * Example 1:
 *
 *
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 * Example 2:
 *
 *
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 * Example 3:
 *
 *
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        size_t ans = 0;
        for (int i = 0; i < words.size(); i++) {
            unordered_set<char> s;
            for (char c : words[i])
                s.insert(c);
            for (int j = i + 1; j < words.size(); j++) {
                bool flag = true;
                for (char c : words[j]) {
                    if (s.count(c)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = max(ans, words[i].size() * words[j].size());
                }
            }
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
