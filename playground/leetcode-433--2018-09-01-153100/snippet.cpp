// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (35.77%)
 * Total Accepted:    15.4K
 * Total Submissions: 43K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from "A", "C", "G", "T".
 *
 * Suppose we need to investigate about a mutation (mutation from "start" to
 * "end"), where ONE mutation is defined as ONE single character changed in the
 * gene string.
 *
 * For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 *
 * Also, there is a given gene "bank", which records all the valid gene
 * mutations. A gene must be in the bank to make it a valid gene string.
 *
 * Now, given 3 things - start, end, bank, your task is to determine what is
 * the minimum number of mutations needed to mutate from "start" to "end". If
 * there is no such a mutation, return -1.
 *
 * Note:
 *
 *
 * Starting point is assumed to be valid, so it might not be included in the
 * bank.
 * If multiple mutations are needed, all mutations during in the sequence must
 * be valid.
 * You may assume start and end string is not the same.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 *
 * return: 1
 *
 *
 *
 *
 * Example 2:
 *
 *
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 *
 * return: 2
 *
 *
 *
 *
 * Example 3:
 *
 *
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 *
 * return: 3
 *
 *
 *
 *
 */
class Solution {
public:
  int minMutation(string start, string end, const vector<string>& bank) {
    size_t n = bank.size() + 1;
    vector<vector<int>> g(n, vector<int>{});
    int e = -1;
    for (int i = 1; i < n; i++) {
      if (adj(start, bank[i-1])) {
        g[0].push_back(i);
      }
      for (int j = 1; j < n; j++) {
        if (adj(bank[j-1], bank[i-1])) {
          g[i].push_back(j);
        }
      }
      if (bank[i-1] == end) e = i;
    }

    vector<int> d(n, -1);
    using pii = pair<int, int>;
    using vii = vector<pii>;

    std::priority_queue<pii, vii, greater<pii>> q;
    q.emplace(0, 0);
    d[0] = 0;
    while (!q.empty()) {
      pii i = q.top();
      int v = i.second;
      int w = i.first;
      q.pop();
      if (v == e) return w;
      for (auto t : g[v]) {
        if (d[t] == -1 || d[v] + 1 < d[t]) {
          d[t] = d[v] + 1;
          q.emplace(d[t], t);
        }
      }
    }
    return -1;
  }

private:
  bool adj(string a, string b) {
    int c = 0;
    for (auto i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) c++;
    }
    return c == 1;
  }
};



int mymain(int argc, char *argv[]) {
    return 0;
}
