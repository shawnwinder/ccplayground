// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * [775] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (55.84%)
 * Total Accepted:    5.7K
 * Total Submissions: 10.3K
 * Testcase Example:
 * '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 *
 *
 * For example, given a 3-ary tree:
 *
 *
 *
 *
 * Return its preorder traversal as: [1,3,5,6,2,4].
 *
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#ifdef CC_PLAYGROUND
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        if (root == NULL)
            return {};
        stack<Node*> stk;
        vector<int> res;
        stk.push(root);
        while (!stk.empty()) {
            Node* temp = stk.top();
            stk.pop();
            for (int i = temp->children.size() - 1; i >= 0; i--)
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
