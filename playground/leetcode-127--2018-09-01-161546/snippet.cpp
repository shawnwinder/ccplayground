// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_set>
#include <vector>

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
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        vector<vector<string>> paths;
        paths.push_back({ beginWord });
        unordered_set<string> visited;
        while (!paths.empty()) {
            vector<vector<string>> paths2;
            unordered_set<string> visited2;
            for (auto& path : paths) {
                string last = path.back();
                for (int i = 0; i < last.size(); ++i) {
                    string news = last;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        news[i] = c;
                        if (!visited.count(news) && wordSet.find(news) != wordSet.end()) {
                            vector<string> newpath = path;
                            newpath.push_back(news);
                            visited2.insert(news);
                            if (news == endWord) {
                                return newpath.size();
                            } else
                                paths2.push_back(newpath);
                        }
                    }
                }
            }
            paths = std::move(paths2);
            visited.insert(visited2.begin(), visited2.end());
        }
        return 0;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
