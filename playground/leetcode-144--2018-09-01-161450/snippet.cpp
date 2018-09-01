// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (48.19%)
 * Total Accepted:    256.2K
 * Total Submissions: 531.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 *   1
 *    \
 *     2
 *    /
 *   3
 *
 * Output: [1,2,3]
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        while (root) {
            TreeNode* l = root->left;
            if (l) {
                while (l->right && l->right != root) {
                    l = l->right;
                }
                if (l->right == nullptr) {
                    l->right = root;
                    ret.push_back(root->val);
                    root = root->left;
                    continue;
                } else {
                    l->right = nullptr;
                }
            } else {
                ret.push_back(root->val);
            }
            root = root->right;
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
