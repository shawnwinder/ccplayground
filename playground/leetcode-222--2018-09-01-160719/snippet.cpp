// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <cmath>
#include <iostream>

using namespace std;

/*
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (28.54%)
 * Total Accepted:    86.3K
 * Total Submissions: 302.5K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Note:
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2h nodes inclusive at the last level h.
 *
 * Example:
 *
 *
 * Input:
 *     1
 *    / \
 *   2   3
 *  / \  /
 * 4   5 6
 *
 * Output: 6
 *
 */

#ifdef CC_PLAYGROUND
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {}
};
#endif

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int dl = 0, dr = 0;
        TreeNode *l = root, *r = root;
        while (l)
            l = l->left, dl++;
        while (r)
            r = r->right, dr++;
        return dl == dr ? pow(2, dl) - 1 : countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
