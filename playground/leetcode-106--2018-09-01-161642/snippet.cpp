// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (35.38%)
 * Total Accepted:    120K
 * Total Submissions: 339.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      if (inorder.empty()) return nullptr;
    return f(&postorder[0], &*postorder.end(), &inorder[0], &*inorder.end());
  }
  TreeNode *f(int *l, int *h, int *ll, int *hh) {
    if (l == h) return nullptr;
    auto r = new TreeNode(h[-1]);
    int *m = find(ll, hh, h[-1]);
    r->left = f(l, l+(m-ll), ll, m);
    r->right = f(l+(m-ll), h-1, m+1, hh);
    return r;
  }
};


int mymain(int argc, char *argv[]) {
    return 0;
}
