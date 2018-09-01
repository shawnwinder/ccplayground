// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (40.84%)
 * Total Accepted:    230.9K
 * Total Submissions: 565.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *  ["ate","eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 *
 *
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97, 101, 103 };
        vector<vector<string>> res;
        unordered_map<int, vector<string>> m;
        for (string& s : strs) {
            int key = 1;
            for (char c : s) {
                key *= prime[c - 'a'];
            }
            m[key].push_back(s);
        }
        transform(m.begin(), m.end(), back_inserter(res),
            [](pair<int, vector<string>> p) { return p.second; });
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
