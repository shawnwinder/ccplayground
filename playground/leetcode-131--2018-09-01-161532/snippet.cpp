// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> good;
    string str;
    int N;
    void work(vector<string>& cur, int pos) {
        if(pos == N) {
            ans.push_back(cur);
            return;
        }
        for(int l=1; l< N - pos + 1; l++ ) {
            if(good[pos][pos + l - 1]) {
                cur.push_back(str.substr(pos, l));
                work(cur, pos + l);
                cur.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        good = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        str = s;
        N = s.size();
        for(int i=0;i<N;i++) {
            for(int j=0; i-j>=0 && i+j<N && s[i-j] == s[i+j]; j++) {
                good[i-j][i+j] = true;
            }
            for(int j=1; i-j>=0 && i+j-1<N && s[i-j] == s[i+j-1]; j++) {
                good[i-j][i+j-1] = true;
            }
        }
        vector<string> cur;
        work(cur, 0);
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
