// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (51.81%)
 * Total Accepted:    324.4K
 * Total Submissions: 626.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 *  1
 *   \
 *    2
 *   /
 *  3
 *
 * Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> s;
        while (root) {
            if (root->left) {
                auto t = root->left;
                while (t->right && t->right != root)
                    t = t->right;
                if (t->right == root) {
                    ans.push_back(root->val);
                    root = root->right;
                    t->right = nullptr;
                } else {
                    t->right = root;
                    root = root->left;
                }
            } else {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }
