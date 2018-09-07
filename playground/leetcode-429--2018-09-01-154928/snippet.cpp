// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [764] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (53.80%)
 * Total Accepted:    5.5K
 * Total Submissions: 10.3K
 * Testcase Example:
 * '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 * For example, given a 3-ary tree:
 *
 *
 *
 *
 *
 * We should return its level order traversal:
 *
 *
 *
 *
 *
 *
 * [
 *   [1],
 *   [3,2,4],
 *   [5,6]
 * ]
 *
 *
 *
 *
 * Note:
 *
 *
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 *
 *
 *
 */

#ifdef CC_PLAYGROUND
class Node {
public:
    int val = 0;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                for (auto n : tmp->children)
                    q.push(n);
            }
            res.push_back(level);
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
