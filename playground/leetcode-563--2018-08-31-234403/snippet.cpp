// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [563] Binary Tree Tilt
 *
 * https://leetcode.com/problems/binary-tree-tilt/description/
 *
 * algorithms
 * Easy (46.76%)
 * Total Accepted:    36.1K
 * Total Submissions: 77.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree, return the tilt of the whole tree.
 *
 * The tilt of a tree node is defined as the absolute difference between the
 * sum of all left subtree node values and the sum of all right subtree node
 * values. Null node has tilt 0.
 *
 * The tilt of the whole tree is defined as the sum of all nodes' tilt.
 *
 * Example:
 *
 * Input:
 *         1
 *       /   \
 *      2     3
 * Output: 1
 * Explanation:
 * Tilt of node 2 : 0
 * Tilt of node 3 : 0
 * Tilt of node 1 : |2-3| = 1
 * Tilt of binary tree : 0 + 0 + 1 = 1
 *
 *
 *
 * Note:
 *
 * The sum of node values in any subtree won't exceed the range of 32-bit
 * integer.
 * All the tilt values won't exceed the range of 32-bit integer.
 *
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
    int res = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        res += abs(l - r);
        return l + r + root->val;
    }

public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
