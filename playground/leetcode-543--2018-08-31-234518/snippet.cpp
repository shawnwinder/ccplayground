// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (45.14%)
 * Total Accepted:    77.5K
 * Total Submissions: 171.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 *          1
 *         / \
 *        2   3
 *       / \
 *      4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
 */

#ifdef CC_PLAYGROUND
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) {}
};
#endif

class Solution {
    int maxdiadepth = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);
        if (leftdepth + rightdepth > maxdiadepth)
            maxdiadepth = leftdepth + rightdepth;
        return max(leftdepth + 1, rightdepth + 1);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxdiadepth;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
