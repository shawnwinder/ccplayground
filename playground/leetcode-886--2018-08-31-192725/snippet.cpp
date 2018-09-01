// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * [922] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (36.71%)
 * Total Accepted:    4.2K
 * Total Submissions: 11.3K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 *
 * Each person may dislike some other people, and they should not go into the
 * same group.
 *
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 *
 * Return true if and only if it is possible to split everyone into two groups
 * in this way.
 *
 *
 * Example 1:
 *
 *
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 *
 *
 *
 *
 */
class Solution {
public:
    // TLE
    // bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    //     vector<vector<int>> g(N + 1);
    //     vector<bool> vs(N + 1);
    //     for (auto & elem : dislikes) {
    //         g[elem[0]].push_back(elem[1]);
    //         g[elem[1]].push_back(elem[0]);
    //         vs[elem[0]] = false;
    //         vs[elem[1]] = false;
    //     }
    //     auto traverse = [&](int v) {
    //         vector<int> visit(N + 1);
    //         auto y = [&](auto &&z, int v, int level) -> bool {
    //             visit[v] = level;
    //             for (auto v2 : g[v]) {
    //                 if (visit[v2] && (level - visit[v2]) % 2 == 0)
    //                     return true;
    //                 if (!visit[v2] && !vs[v2])
    //                 {
    //                     if (z(z, v2, level + 1))
    //                         return true;
    //                 }
    //             }
    //             visit[v] = 0;
    //             return false;
    //         };
    //         return y(y, v, 1);
    //     };
    //     for (auto i = 1; i <= N; ++i) {
    //         vs[i] = true;
    //         if (traverse(i)) return false;
    //     }
    //     return true;
    // }

    bool paintNodeValid(
        vector<vector<int>>& edges, vector<int>& nodeColor, int node, int colorToPaint) {
        // unpainted: 0; painted: -1 or 1.
        if (nodeColor[node] != 0) {
            return nodeColor[node] == colorToPaint;
        }
        nodeColor[node] = colorToPaint;
        for (int i = 0; i < edges[node].size(); i++) {
            if (!paintNodeValid(edges, nodeColor, edges[node][i], colorToPaint * -1)) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> edges(N + 1, vector<int>());
        for (auto dislike : dislikes) {
            edges[dislike[0]].push_back(dislike[1]);
            edges[dislike[1]].push_back(dislike[0]);
        }
        vector<int> nodeColor(N + 1, 0);
        return paintNodeValid(edges, nodeColor, 1, 1);
    }
};

int mymain(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> d = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
    cout << s.possibleBipartition(4, d);
    return 0;
}
