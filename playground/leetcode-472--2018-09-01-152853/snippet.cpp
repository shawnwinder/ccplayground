// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

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
 * Testcase Example:
 * '["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]'
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
 * The length sum of elements in the given array will not exceed 600,000.
 * All the input string will only include lower case letters.
 * The returned elements order does not matter.
 *
 *
 */
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<size_t> c;
        for (auto& w : words) {
            if (w.empty())
                continue;
            size_t h = 0;
            for (char c : w)
                h = h * 97 + c;
            c.insert(h);
        }
        vector<string> r;
        for (auto& w : words) {
            if (w.empty())
                continue;
            vector<char> f(w.size() + 1);
            f[w.size()] = 1;
            for (auto i = w.size(); i-- > 0;) {
                size_t h = 0;
                for (auto j = i; j < (i ? w.size() : w.size() - 1); ++j) {
                    h = h * 97 + w[j];
                    if (f[j + 1] && c.count(h)) {
                        f[i] = true;
                        break;
                    }
                }
            }
            if (f[0])
                r.push_back(w);
        }
        return r;
    }
};

int mymain(int argc, char* argv[]) {
    vector<string> x = { "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat",
        "ratcatdogcat" };
    Solution s;
    for (auto& y : s.findAllConcatenatedWordsInADict(x))
        std::cout << y << std::endl;
    return 0;
}
