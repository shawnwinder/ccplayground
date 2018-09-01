// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (39.10%)
 * Total Accepted:    249.6K
 * Total Submissions: 638.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.
 *
 *
 * Example 1:
 *
 * Given the following tree [3,9,20,null,null,15,7]:
 *
 *
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 * Return true.
 *
 * Example 2:
 *
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 *
 *
 *       1
 *      / \
 *     2   2
 *    / \
 *   3   3
 *  / \
 * 4   4
 *
 *
 * Return false.
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
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        if (l < 0 || r < 0 || abs(l - r) > 1)
            return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) { return height(root) >= 0; }
};

int mymain(int argc, char* argv[]) { return 0; }
