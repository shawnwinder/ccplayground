// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (25.22%)
 * Total Accepted:    125.1K
 * Total Submissions: 496.1K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 *
 */
class Solution {
    unordered_map<string, vector<string>> m;
    unordered_set<string> dict;
    vector<string> combine(string word, vector<string> prev) {
        for (int i = 0; i < prev.size(); ++i) {
            prev[i] += " " + word;
        }
        return prev;
    }
    vector<string> wordBreak(string& s) {
        if (m.count(s))
            return m[s]; // take from memory
        vector<string> result;
        if (dict.count(s)) { // a whole string is a word
            result.push_back(s);
        }
        for (int i = 1; i < s.size(); ++i) {
            string word = s.substr(i);
            if (dict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(rem));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s] = result; // memorize
        return result;
    }
public:
    vector<string> wordBreak(string& s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        return wordBreak(s);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
