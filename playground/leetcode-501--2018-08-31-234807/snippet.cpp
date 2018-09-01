// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (37.90%)
 * Total Accepted:    40.6K
 * Total Submissions: 107.2K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 *
 * For example:
 * Given BST [1,null,2,2],
 *
 *
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 *
 *
 *
 *
 * return [2].
 *
 * Note: If a tree has more than one mode, you can return them in any order.
 *
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
   vector<int> findMode(TreeNode* root) {
     vector<int> ret;
     int last = 0;
     int cnt = 0;
     int ans = 0;

     while (root) {
       auto l = root->left;
       if (l) {
         while (l->right && l->right != root) l = l->right;
         if (l->right == root) {
           l->right = nullptr;
         } else {
           l->right = root;
           root = root->left;
           continue;
         }
       }
       if (ret.empty() || last == root->val) cnt ++; else cnt = 1;
       if (cnt > ans) {ans = cnt; ret = { root-> val} ; }
       else if (cnt == ans) ret.push_back(root->val);
       last = root->val;
       root = root -> right;
     }
     return ret;
   }
 };


int mymain(int argc, char *argv[]) {
    return 0;
}
