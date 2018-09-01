// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (25.17%)
 * Total Accepted:    165.8K
 * Total Submissions: 658.8K
 * Testcase Example:  '{}'
 *
 *
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 *
 *
 *
 *
 * OJ's undirected graph serialization:
 *
 *
 * Nodes are labeled uniquely.
 *
 *
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 *
 *
 *
 *
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 *
 *
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 *
 *
 *
 *
 * Visually, the graph looks like the following:
 *
 *       1
 *      / \
 *     /   \
 *    0 --- 2
 *         / \
 *         \_/
 *
 *
 *
 *
 */

#ifdef CC_PLAYGROUND
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x)
        : label(x){};
};
#endif

class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> m;
    void walk(UndirectedGraphNode* node) {
        int label = node->label;
        if (m.find(label) != m.end()) {
            return;
        } else {
            m[label] = new UndirectedGraphNode(label);
        }
        for (int i = 0; i < node->neighbors.size(); i++) {
            walk(node->neighbors[i]);
            m[label]->neighbors.push_back(m[node->neighbors[i]->label]);
        }
    }
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == NULL)
            return NULL;
        walk(node);
        return m[node->label];
    }
};

int mymain(int argc, char* argv[]) { return 0; }
