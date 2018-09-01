// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (47.95%)
 * Total Accepted:    99K
 * Total Submissions: 206.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        while (root) {
            TreeNode* l = root->left;
            if (l) {
                while (l->right && l->right != root) l = l->right;
                if (l->right != root) {
                    TreeNode* tmp = root;
                    root = root->left;
                    if (!root->left && !root->right) ret += root->val;
                    l->right = tmp;
                    continue;
                } else {
                    l->right = nullptr;
                }
            }
            root = root->right;
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
