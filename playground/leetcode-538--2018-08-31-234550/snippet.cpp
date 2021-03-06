// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (48.85%)
 * Total Accepted:    52.9K
 * Total Submissions: 108.3K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 *
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 *              5
 *            /   \
 *           2     13
 *
 * Output: The root of a Greater Tree like this:
 *             18
 *            /   \
 *          20     13
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
    int cur_sum = 0;

    void travel(TreeNode* root) {
        if (!root)
            return;
        if (root->right)
            travel(root->right);
        root->val = (cur_sum += root->val);
        if (root->left)
            travel(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
