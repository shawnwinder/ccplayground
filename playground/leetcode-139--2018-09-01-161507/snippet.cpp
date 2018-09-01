// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (32.40%)
 * Total Accepted:    239.8K
 * Total Submissions: 740.3K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
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
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 */
 class Solution {
 public:
   bool work(int start, vector<bool>& rem, string& s, unordered_set<string>& m) {
     if (start >= s.size()) return true;
     rem[start] = true;
     vector<int> ans;
     for (int i = start; i < s.size(); ++i) {
       if (m.find(s.substr(start, i-start + 1)) != m.end()) {
         ans.push_back(i+1);
       }
     }
     for (int i = ans.size() -1; i >= 0; --i) {
       if(!rem[ans[i]] && work(ans[i], rem, s, m)) return true;
     }
     return false;
   }
   bool wordBreak(string s, vector<string> wordDict) {
     unordered_set<string> m(wordDict.begin(), wordDict.end());
     vector<bool> rem(s.size(), false);
     return work(0, rem, s, m);
   }
 };



int mymain(int argc, char *argv[]) {
    return 0;
}
