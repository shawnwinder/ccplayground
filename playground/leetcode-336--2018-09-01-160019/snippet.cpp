// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (27.84%)
 * Total Accepted:    45.1K
 * Total Submissions: 162K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 *
 * Example 1:
 *
 *
 *
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 *
 *
 *
 */
class Solution {
public:
    // palindromePairs (words):
    // ans = {{}}
    // For each word in the words:
    // 1. Find its suffix palindromes.
    // 	For each suffix palindrome:
    // 		let word' = reverse(word.substr(0, word.len - suffix.len))
    // 		if word' exists:
    // 			put { word_index , word'_index } into ans

    // 2. Find its prefix palindromes.
    // 	For each prefix palindrome.
    // 		let word' = reverse(word.substr(prefix.len))
    // 		if(word' exists):
    // 			put {word'_index, word_index} into ans

    // 3. Let word' = reverse of word.
    // 	if word' exists:
    // 		put {word_index, word' index} into ans

    // 4. If word itself is a palindrome
    // 	Look up an empty string ""
    // 	if "" exists:
    // 		put {word_index, ""_index} into ans
    // return ans

    // calculatePrefixAndSuffixPalindromes:
    // prefixPalindromes = {}
    // suffixPalindromes = {}
    // Processing Manacher's algorithm with below modifications:
    // 		if palindrome reaches begining of the string:
    // 			put it to prefixPalindromes
    // 		if palindrome reaches end of the string:
    // 			put it to suffixPalindromes
    // return prefixPalindromes and suffixPalindromes

    string a;
    vector<int> z;
    void manacher(int n) {
        z.resize(n);
        z[0] = 1;
        for (int f, g = 1, i = 1; i < n; i++)
            if (i < g && z[2 * f - i] != g - i)
                z[i] = min(z[2 * f - i], g - i);
            else {
                g = max(g, f = i);
                for (; g < n && 2 * f - g >= 0 && a[2 * f - g] == a[g]; g++)
                    ;
                z[f] = g - f;
            }
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_multimap<string, int> ls, rs;
        for (auto i = 0; i < words.size(); ++i) {
            string& w = words[i];
            int n = w.size(), nn = 2 * n + 1;
            a = string(nn, '.');
            for (auto j = 0; j < n; ++j)
                a[2 * j + 1] = w[j];
            manacher(nn);
            for (auto j = 0u; j < nn; ++j) {
                if (z[j] == j + 1)
                    ls.emplace(w.substr((j + z[j]) / 2), i);
                if (j + z[j] == nn)
                    rs.emplace(w.substr(0, (j - z[j] + 1) / 2), i);
            }
        }
        vector<vector<int>> ret;
        for (auto i = 0; i < words.size(); ++i) {
            string w = words[i], ww = w;
            reverse(ww.begin(), ww.end());
            auto its = ls.equal_range(ww);
            for (auto it = its.first; it != its.second; ++it)
                if (it->second != i)
                    ret.push_back(vector<int>{ i, it->second });
            its = rs.equal_range(ww);
            for (auto it = its.first; it != its.second; ++it)
                if (w.size() < words[it->second].size())
                    ret.push_back(vector<int>{ it->second, i });
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
