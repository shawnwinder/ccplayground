// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (15.47%)
 * Total Accepted:    91.2K
 * Total Submissions: 589.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 *
 *
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return an empty list if there is no such transformation sequence.
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
 * Output:
 * [
 *  ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
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
 * Output: []
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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
                                ans.push_back(newpath);
                            } else
                                paths2.push_back(newpath);
                        }
                    }
                }
            }
            if (ans.size())
                break;
            paths = std::move(paths2);
            visited.insert(visited2.begin(), visited2.end());
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
