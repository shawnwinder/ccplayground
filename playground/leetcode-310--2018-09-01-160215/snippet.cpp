// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (29.13%)
 * Total Accepted:    49.6K
 * Total Submissions: 170.3K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For a undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 *
 * Example 1 :
 *
 *
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 *        0
 *        |
 *        1
 *       / \
 *      2   3
 *
 * Output: [1]
 *
 *
 * Example 2 :
 *
 *
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 *     0  1  2
 *      \ | /
 *        3
 *        |
 *        4
 *        |
 *        5
 *
 * Output: [3, 4]
 *
 * Note:
 *
 *
 * According to the definition of tree on Wikipedia: "a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree."
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 *
 *
 */
class Solution {
    vector<vector<int>> g;
    vector<int> parent;
    // diameter
    int bfs(int u) {
        queue<int> q;
        int leaf = u;
        fill(parent.begin(), parent.end(), -1);
        parent[u] = -2;
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            leaf = u;
            for (int v : g[u])
                if (parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
        }
        return leaf;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        g.resize(n);
        parent.resize(n);
        for (auto& e : edges) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        vector<int> ancestors;
        for (int v = bfs(bfs(0)); v != -2; v = parent[v])
            ancestors.push_back(v);
        vector<int> ret{ ancestors[ancestors.size() / 2] };
        if (ancestors.size() % 2 == 0)
            ret.push_back(ancestors[ancestors.size() / 2 - 1]);
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
