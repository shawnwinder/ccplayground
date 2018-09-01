// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [472] Concatenated Words
 *
 * https://leetcode.com/problems/concatenated-words/description/
 *
 * algorithms
 * Hard (31.82%)
 * Total Accepted:    14.1K
 * Total Submissions: 44.3K
 * Testcase Example:  '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
 *
 * Given a list of words (without duplicates), please write a program that
 * returns all concatenated words in the given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array.
 *
 * Example:
 *
 * Input:
 * ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 *
 * Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 *
 * Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 * "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat"
 * can be concatenated by "rat", "cat", "dog" and "cat".
 *
 *
 *
 * Note:
 *
 * The number of elements of the given array will not exceed 10,000
 * The length sum of elements in the given array will not exceed 0,000.
 * All the input string will only include lower case letters.
 * The returned elements order does not matter.
 *
 *
 */
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){
            return s1.length() < s2.length();
        });
        vector<string> res;
        for (auto s : words) {
            wordDict.insert(s);
            dict[s[0]].emplace_back(s);
        }
        for (auto s : words) {
            if (dfs(s)) res.emplace_back(s);    
        }
        return res;
    }
    
    bool dfs(const string& s) {
        if (s.empty()) return false;
        if (found.find(s) != found.end()) return found[s];
        bool res = false;
        for (auto const &ss : dict[s[0]]) {
            int len = ss.length();
            if (len < s.length()) {
                if (ss != s.substr(0, len)) continue;
                string rem = s.substr(len);
                if (wordDict.find(rem) != wordDict.end()) res = true;
                else res |= dfs(rem);
            }
            else break;
            if (res) break;
        }
        found[s] = res;
        return res;
    }
    
    unordered_set<string> wordDict;
    unordered_map<char, vector<string>> dict;
    unordered_map<string, bool> found;
};

int mymain(int argc, char *argv[]) {
    return 0;
}
