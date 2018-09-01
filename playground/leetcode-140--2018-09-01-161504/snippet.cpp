// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
 * a valid dictionary word. Return all such possible sentences.
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
public:
  bool work(vector<vector<string>>& ans, vector<string>& partial, int start, vector<bool>& rem, string& s, unordered_set<string>& m) {
    if (start >= s.size()) {
      ans.push_back(partial);
      return false; // found
    }
    vector<int> temp;
    for (int i = start; i < s.size(); ++i) {
      if (m.find(s.substr(start, i-start + 1)) != m.end()) {
        temp.push_back(i+1);
      }
    }
    bool ret = true;
    for (int i = temp.size() -1; i >= 0; --i) {
      if(!rem[temp[i]]) {
        partial.push_back(s.substr(start, temp[i] - start));
        rem[temp[i]] = work(ans, partial, temp[i], rem, s, m);
        ret &= rem[temp[i]];
        partial.pop_back();
      }
    }
    return ret; // not found
  }

  string join(const vector<string> &elements, const string &separator) {
    if (!elements.empty()) {
        stringstream ss;
        auto it = elements.cbegin();
        while (true) {
          ss << *it++;
          if (it != elements.cend())
            ss << separator;
          else
            return ss.str();
        }
    }
    return "";
  }

 vector<string> wordBreak(string s, vector<string>& wordDict) {
   unordered_set<string> m(wordDict.begin(), wordDict.end());
   vector<bool> rem(s.size(), false);
   vector<vector<string>> ans;
   vector<string> partial;
   work(ans, partial, 0, rem, s, m);
   vector<string> ret;
   for (auto& a : ans) {
     ret.push_back(join(a, " "));
   }
   return ret;
 }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
