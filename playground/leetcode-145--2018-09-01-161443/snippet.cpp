// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (44.02%)
 * Total Accepted:    198.6K
 * Total Submissions: 451.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [3,2,1]
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    TreeNode* reverse(TreeNode* root) {
        TreeNode* l = nullptr;
        while (root) {
            auto tmp = root;
            root = root->right;
            tmp->right = l;
            l = tmp;
        }
        return l;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        TreeNode* proot = new TreeNode(0);
        proot->left = root;
        root = proot;
        vector<int> ret;
        while (root) {
            auto l = root->left;
            if (l) {
                while (l->right && l->right != root) {
                    l = l->right;
                }
                // go left
                if (l->right == nullptr) {
                    l->right = root;
                    root = root->left;
                } else { // back from left
                    l->right = nullptr;
                    auto h = reverse(root->left);
                    while (h) {
                        ret.push_back(h->val);
                        h = h->right;
                    }
                    reverse(l);
                    root = root->right;
                }
            } else { // no left
                root = root->right;    
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
