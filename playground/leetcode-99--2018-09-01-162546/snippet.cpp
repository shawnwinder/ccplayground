// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (32.08%)
 * Total Accepted:    96.5K
 * Total Submissions: 300.7K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Example 1:
 *
 *
 * Input: [1,3,null,null,2]
 *
 *   1
 *  /
 * 3
 *  \
 *   2
 *
 * Output: [3,1,null,null,2]
 *
 *   3
 *  /
 * 1
 *  \
 *   2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,4,null,null,2]
 *
 *     3
 *    / \
 *   1   4
 *  /
 * 2
 *
 * Output: [2,1,4,null,null,3]
 *
 *   2
 *  / \
 * 1   4
 *    /
 *   3
 *
 *
 * Follow up:
 *
 *
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        TreeNode *p = nullptr, *u = nullptr, *v;
        while (root) {
            auto l = root->left;
            if (l) {
                while (l->right && l->right != root) {
                    l = l->right;
                }
                if (!l->right) {
                    l->right = root;
                    root = root->left;
                    continue;
                } else {
                    l->right = nullptr;
                }
            }
            if (p && p->val > root->val) {
                if (!u) {
                    u = p;
                }
                v = root;
            }
            p = root;
            root = root->right;
        }
        swap(u->val, v->val);
    }
};

int mymain(int argc, char* argv[]) { return 0; }
