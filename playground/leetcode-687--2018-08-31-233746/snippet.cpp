// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (32.70%)
 * Total Accepted:    34.7K
 * Total Submissions: 106K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 *
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 *
 *              5
 *             / \
 *            4   5
 *           / \   \
 *          1   1   5
 *
 *
 *
 *
 * Output:
 *
 * 2
 *
 *
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input:
 *
 *              1
 *             / \
 *            4   5
 *           / \   \
 *          4   4   5
 *
 *
 *
 *
 * Output:
 *
 * 2
 *
 *
 *
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {

    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
