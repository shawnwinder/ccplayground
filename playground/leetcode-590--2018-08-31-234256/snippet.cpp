// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * [776] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (59.48%)
 * Total Accepted:    6K
 * Total Submissions: 10.1K
 * Testcase Example:
 * '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 *
 *
 * For example, given a 3-ary tree:
 *
 *
 *
 *
 * Return its postorder traversal as: [5,6,3,2,4,1].
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
    vector<int> postorder(Node* root) {
        if (root == NULL)
            return {};
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* temp = stk.top();
            stk.pop();
            for (int i = 0; i < temp->children.size(); i++)
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
