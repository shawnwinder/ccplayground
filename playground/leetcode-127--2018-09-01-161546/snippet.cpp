// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (20.91%)
 * Total Accepted:    184.7K
 * Total Submissions: 883.3K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */
class Solution {
public:
    bool adj(string& a, string& b) {
        if (a.size() != b.size()) return false;
        int cnt = 0;
        for (int i=0;i<a.size();i++) {
            cnt += a[i] != b[i];
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> g (n);
        wordList.push_back(beginWord);
        sort(wordList.begin(), wordList.end());
        wordList.erase(unique(wordList.begin(), wordList.end()), wordList.end());
        int s = -1, t = -1;
        for (int i=0;i<n;i++) {
            if (wordList[i] == beginWord) s = i;
            else if (wordList[i] == endWord) t = i;
            for (int j=i+1;j<n;j++) {
                if (adj(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        if (t == -1) return 0;
        if (s == t) return 1;
        unordered_set<int> visit;
        vector<unordered_set<int>> be(2);
        be[0].insert(s);
        be[1].insert(t);
        visit.insert(s);
        visit.insert(t);
        int ret = 2;
        int idx = 0;
        while (!be[idx].empty()) {
            unordered_set<int> aug;
            for (int c : be[idx]) {
                for (int i : g[c]) {
                    if (be[1-idx].count(i) > 0) {
                        return ret;
                    } else if (visit.find(i) == visit.end()) {
                        aug.insert(i);
                        visit.insert(i);
                    }
                }
            }
            ret ++;
            be[idx] = aug;
            idx = 1-idx;
        }
        return 0;
    }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
