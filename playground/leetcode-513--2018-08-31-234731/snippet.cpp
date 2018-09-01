// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (56.77%)
 * Total Accepted:    52.7K
 * Total Submissions: 92.9K
 * Testcase Example:  '[2,1,3]'
 *
 *
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *
 *
 * Example 1:
 *
 * Input:
 *
 *   2
 *  / \
 * 1   3
 *
 * Output:
 * 1
 *
 *
 *
 * ⁠ Example 2:
 *
 * Input:
 *
 *       1
 *      / \
 *     2   3
 *    /   / \
 *   4   5   6
 *      /
 *     7
 *
 * Output:
 * 7
 *
 *
 *
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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
    int ans = 0;
    int row = 0;
    int mrow = 0;
    int findBottomLeftValue(TreeNode* root) {
        row ++;
        if (root == NULL) return 0;
        if (row > mrow) {
            mrow = row;
            ans = root->val;
        }
        findBottomLeftValue(root->left);
        row --;
        findBottomLeftValue(root->right);
        row --;
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
