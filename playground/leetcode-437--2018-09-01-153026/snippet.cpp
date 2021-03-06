// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (40.40%)
 * Total Accepted:    69.6K
 * Total Submissions: 172.3K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 *      10
 *     /  \
 *    5   -3
 *   / \    \
 *  3   2   11
 * / \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    int f(TreeNode* root, int pre, int sum) {
        if (!root)
            return 0;
        int cur = pre + root->val;
        return (cur == sum) + f(root->left, cur, sum) + f(root->right, cur, sum);
    }

public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        return f(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
