// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [784] Insert into a Binary Search Tree
 *
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (56.96%)
 * Total Accepted:    5K
 * Total Submissions: 8.8K
 * Testcase Example:  '[4,2,7,1,3]\n5'
 *
 * Given the root node of a binary search tree (BST) and a value to be inserted
 * into the tree, insert the value into the BST. Return the root node of the
 * BST after the insertion. It is guaranteed that the new value does not exist
 * in the original BST.
 *
 * Note that there may exist multiple valid ways for the insertion, as long as
 * the tree remains a BST after insertion. You can return any of them.
 *
 * For example, 
 *
 *
 * Given the tree:
 *       4
 *      / \
 *     2   7
 *    / \
 *   1   3
 * And the value to insert: 5
 *
 *
 * You can return this binary search tree:
 *
 *
 *        4
 *      /   \
 *     2     7
 *    / \   /
 *   1   3 5
 *
 *
 * This tree is also valid:
 *
 *
 *        5
 *      /   \
 *     2     7
 *    / \
 *   1   3
 *        \
 *         4
 *
 */

#ifdef CC_PLAYGROUND
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val <= root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}


int mymain(int argc, char *argv[]) {
    return 0;
}
