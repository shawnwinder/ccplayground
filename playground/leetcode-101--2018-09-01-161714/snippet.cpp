// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (41.29%)
 * Total Accepted:    287.2K
 * Total Submissions: 695.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 * But the following [1,2,2,null,3,null,3]  is not:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        vector<int> lporder;
        vector<int> liorder;
        vector<int> rporder;
        vector<int> riorder;
        auto pr = root;
        while (root) {
            lporder.push_back(root->val);
            auto l = root->left;
            if (l) {
                while (l->right && l->right != root) l = l->right;
                if (l->right == root) { // back from left
                    l->right = nullptr;
                } else { // go left
                    l->right = root;
                    root = root->left;
                    continue;
                }
            } 
            // no left
            liorder.push_back(root->val);
            root = root->right;
        }
        root = pr;
        while (root) {
            rporder.push_back(root->val);
            auto r = root->right;
            if (r) {
                while (r->left && r->left != root) r = r->left;
                if (r->left == root) { // back from right
                    r->left = nullptr;
                } else { // go right
                    r->left = root;
                    root = root->right;
                    continue;
                }
            } 
            // no right
            riorder.push_back(root->val);
            root = root->left;
        }
        return lporder == rporder && liorder == riorder;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}
