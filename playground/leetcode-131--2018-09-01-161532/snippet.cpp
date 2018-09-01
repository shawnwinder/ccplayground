// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (37.12%)
 * Total Accepted:    131.8K
 * Total Submissions: 355.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output:
 * [
 *  ["aa","b"],
 *  ["a","a","b"]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s.empty())
            return ret;
        vector<string> path;
        dfs(0, s, path, ret);
        return ret;
    }
    void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& ret) {
        if (index == s.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, ret);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
