// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (43.12%)
 * Total Accepted:    39K
 * Total Submissions: 90.4K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[
 * ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 *
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 *
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values,
        vector<pair<string, string>> queries) {
        unordered_map<string, int> idx;
        int n = 0;
        for (auto p : equations) {
            auto x = idx.find(p.first);
            if (x == idx.end())
                idx[p.first] = n++;
            auto y = idx.find(p.second);
            if (y == idx.end())
                idx[p.second] = n++;
        }
        vector<vector<double>> m(n, vector<double>(n, NAN));
        for (int j = 0; j < values.size(); j++) {
            int a = idx[equations[j].first];
            int b = idx[equations[j].second];
            m[a][b] = values[j];
            m[b][a] = values[j] == 0 ? NAN : 1 / values[j];
        }
        for (int i = 0; i < n; i++)
            m[i][i] = 1;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!isnan(m[i][k]) && !isnan(m[k][j])) {
                        m[i][j] = m[i][k] * m[k][j];
                    }
                }
            }
        }
        vector<double> ret;
        for (auto q : queries) {
            auto x = idx.find(q.first);
            auto y = idx.find(q.second);
            if (x == idx.end() || y == idx.end())
                ret.push_back(-1);
            else {
                double v = m[x->second][y->second];
                if (!isnan(v))
                    ret.push_back(v);
                else
                    ret.push_back(-1);
            }
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
