// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [918] Reachable Nodes In Subdivided Graph
 *
 * https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/
 *
 * algorithms
 * Hard (33.58%)
 * Total Accepted:    1.4K
 * Total Submissions: 4.3K
 * Testcase Example:  '[[0,1,10],[0,2,1],[1,2,2]]\n6\n3'
 *
 * Starting with an undirected graph (the "original graph") with nodes from 0
 * to N-1, subdivisions are made to some of the edges.
 *
 * The graph is given as follows: edges[k] is a list of integer pairs (i, j, n)
 * such that (i, j) is an edge of the original graph,
 *
 * and n is the total number of new nodes on that edge.
 *
 * Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1,
 * x_2, ..., x_n) are added to the original graph,
 *
 * and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n),
 * (x_n, j) are added to the original graph.
 *
 * Now, you start at node 0 from the original graph, and in each move, you
 * travel along one edge.
 *
 * Return how many nodes you can reach in at most M moves.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
 * Output: 13
 * Explanation:
 * The nodes that are reachable in the final graph after M = 6 moves are
 * indicated below.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
 * Output: 23
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= edges.length <= 10000
 * 0 <= edges[i][0] < edges[i][1] < N
 * There does not exist any i != j for which edges[i][0] == edges[j][0] and
 * edges[i][1] == edges[j][1].
 * The original graph has no parallel edges.
 * 0 <= edges[i][2] <= 10000
 * 0 <= M <= 10^9
 * 1 <= N <= 3000
 * A reachable node is a node that can be travelled to using at most M moves
 * starting from node 0.
 *
 *
 *
 *
 *
 *
 */
class Solution {
public:
    // Store `edges` to another 2D hashtable `e`, so that we can easier get
    // length between two node by `e[i][j]`. `seen[i]` means that we can arrive
    // at node `i` and have `seen[i]` moves left. We use Dijkstra algorithm in
    // this solution. Priority queue `pq` store states `(moves left, node
    // index)`. So every time when we pop from `pq`, we get the state with the
    // most moves left. In the end, we calculate the number of nodes that we can
    // reach. `res = seen.length` For every edge `e[i][j]`: `res += min(seen[i]
    // + seen[j], e[i][j])`
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> e;
        for (auto v : edges)
            e[v[0]][v[1]] = e[v[1]][v[0]] = v[2];
        priority_queue<pair<int, int>> pq;
        pq.push({ M, 0 });
        unordered_map<int, int> seen;
        while (pq.size()) {
            int moves = pq.top().first, i = pq.top().second;
            pq.pop();
            if (!seen.count(i)) {
                seen[i] = moves;
                for (auto j : e[i]) {
                    int moves2 = moves - j.second - 1;
                    if (!seen.count(j.first) && moves2 >= 0)
                        pq.push({ moves2, j.first });
                }
            }
        }
        int res = seen.size();
        for (auto v : edges) {
            int a = seen.find(v[0]) == seen.end() ? 0 : seen[v[0]];
            int b = seen.find(v[1]) == seen.end() ? 0 : seen[v[1]];
            res += min(a + b, v[2]);
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
