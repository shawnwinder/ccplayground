// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <climits>
#include <iostream>

using namespace std;

/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.38%)
 * Total Accepted:    276.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 * Example 1:
 *
 *
 * Input:
 *   2
 *  / \
 * 1   3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 *    5
 *   / \
 *  1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
public:
    bool isValidBST(TreeNode* root) {
        bool flag = false;
        int last;
        auto p = root;
        while (p) {
            auto l = p->left;
            if (l) {
                while (l->right && l->right != p)
                    l = l->right;
                if (l->right == p) {
                    l->right = nullptr;
                } else {
                    l->right = p;
                    p = p->left;
                    continue;
                }
            }
            if (flag && last >= p->val) {
                // stupid OJ cannot destruct the tree
                root->left = nullptr;
                root->right = nullptr;
                return false;
            }
            flag = true;
            last = p->val;
            p = p->right;
        }
        return true;
    }
};

int mymain(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    Solution s;
    cout << s.isValidBST(root);
    return 0;
}
