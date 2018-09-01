// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (27.81%)
 * Total Accepted:    141.8K
 * Total Submissions: 510.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 *
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 *
 * Output: 42
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
    int g(int a) {
        if(a<0) return 0;else return a;
    }
    int ans = -1000000000;
    int work(TreeNode* root) {
        if(root == NULL) return 0;
        int lmax = work(root->left);
        int rmax = work(root->right);
        int s = g(lmax)+g(rmax) + root->val;
        if(s > ans) ans = s;
        return g(lmax>rmax?lmax:rmax) + root->val;   
    }
    int maxPathSum(TreeNode* root) {
        work(root);
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
