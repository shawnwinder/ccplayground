// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <climits>

using namespace std;

/*
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (48.29%)
 * Total Accepted:    43.2K
 * Total Submissions: 89.5K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 *
 *
 * Example:
 *
 * Input:
 *
 *   1
 *    \
 *     3
 *    /
 *   2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 *
 *
 *
 *
 * Note:
 * There are at least two nodes in this BST.
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
    int min_dif = INT_MAX, val = -1;

public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left != NULL)
            getMinimumDifference(root->left);
        if (val >= 0)
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL)
            getMinimumDifference(root->right);
        return min_dif;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
