// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
 * ⁠ ["hit","hot","dot","dog","cog"],
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
  vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    wordList.insert(beginWord);
    wordList.insert(endWord);
    size_t n = wordList.size();
    vector<vector<int>> g(n, vector<int>{});
    vector<string> m(n, "");
    int s, e;
    int i = 0;
    {
      PB("construct");
      unordered_map<string, int> wm;
      for (auto& x : wordList) {
        wm.emplace(x, i++);
      }
      for (auto& p : wm) {
        auto w = p.first;
        i = p.second;
        m[i] = w;
        if (beginWord == w) {
          s = i;
        }
        if (endWord == w) {
          e = i;
        }
        for (auto& c : w) {
          char c0 = c;
          for (c = 'a'; c <= 'z'; c ++) {
            if (c == c0) continue;
            auto it = wm.find(w);
            if (it != wm.end()) g[i].push_back(it->second);
          }
          c = c0;
        }
      }
    }
    using pii = pair<int, int>;
    using vii = vector<pii>;
    vector<pair<int, vector<int>>> d(n, {-1, {}});

    std::priority_queue<pii, vii, greater<pii>> q;
    q.emplace(0, s);
    d[s] = {0, {}};
    {
      PB("dijkstra");
    while (!q.empty()) {
      pii i = q.top();
      int v = i.second;
      int w = i.first;
      q.pop();
      if (v == e) break;
      for (auto t : g[v]) {
        if (d[t].first == -1 || d[v].first + 1 < d[t].first) {
          d[t] = {d[v].first + 1, {v}};
          q.emplace(d[t].first, t);
        } else if (d[v].first + 1 == d[t].first) {
          d[t].second.push_back(v);
        }
      }
    }

    }
    vector<vector<string>> ret;
    list<string> l;
    {
      PB("print");
      printPath(e, l, s, d, m, ret);

    }
    return ret;
  }

private:
  bool adj(string a, string b) {
    int c = 0;
    for (auto i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) c++;
    }
    return c == 1;
  }

  void printPath(int t, list<string>& l, int s,
                 vector<pair<int, vector<int>>>& d,
                 vector<string>& m,
                 vector<vector<string>>& res) {
    l.push_front(m[t]);
    if (t == s) {
      res.emplace_back(l.begin(), l.end());
    } else {
      for (int v : d[t].second) {
        printPath(v, l, s, d, m, res);
      }
    }
    l.pop_front();
  }

};

#ifdef AMOS
int main() {
  ios::sync_with_stdio(false);
  Solution s;
  unordered_set<string> v {"dot"};
  s.findLadders("hot", "dog", v);
}
#endif


int mymain(int argc, char *argv[]) {
    return 0;
}
